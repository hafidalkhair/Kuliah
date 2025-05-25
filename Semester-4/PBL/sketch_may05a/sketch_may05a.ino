#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHT11PIN 4
#define RELAY_PIN 13  // Gunakan pin GPIO 13 untuk relay

const char* ssid = "HOMESTAY V2";       
const char* password = "perubahan";

const char* mqtt_server = "mqtt.esp32.my.id";
const int mqtt_port = 7931;
const char* mqtt_user = "tamu";
const char* mqtt_pass = "tamu2024";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT11PIN, DHT11);

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Matikan relay saat awal (aktif LOW)

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);

  // Relay logic (aktif LOW)
  if (temp > 30.0) {
    digitalWrite(RELAY_PIN, LOW);  // Relay ON
  } else if (temp < 25.0) {
    digitalWrite(RELAY_PIN, HIGH); // Relay OFF
  }

  // Kirim data ke MQTT
  client.publish("esp32/temperature", String(temp).c_str());
  client.publish("esp32/humidity", String(humi).c_str());

  delay(5000); // jeda pengiriman tiap 5 detik
}

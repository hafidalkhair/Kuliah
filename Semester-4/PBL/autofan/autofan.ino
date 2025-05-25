#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHT11PIN 4          // Pin data sensor DHT11
#define RELAY_PIN 13        // Relay dihubungkan ke pin GPIO 13

// Konfigurasi WiFi
const char* ssid = "HOMESTAY V2";
const char* password = "perubahan";

// Konfigurasi MQTT
const char* mqtt_server = "mqtt.esp32.my.id";
const int mqtt_port = 7931;
const char* mqtt_user = "tamu";
const char* mqtt_pass = "tamu2024";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT11PIN, DHT11);

void setup_wifi() {
  delay(10);
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi terhubung");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Menghubungkan ke MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("Terhubung ke MQTT broker");
    } else {
      Serial.print("Gagal, rc=");
      Serial.print(client.state());
      Serial.println(" coba lagi dalam 5 detik");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF saat awal (aktif LOW)

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

  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.print("°C | Kelembapan: ");
  Serial.print(humi);
  Serial.println("%");

  // Logika kipas (aktif LOW)
  if (temp > 29.0) {
    digitalWrite(RELAY_PIN, LOW);  // Kipas ON
    client.publish("esp32/fan_status", "ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Kipas OFF
    client.publish("esp32/fan_status", "OFF");
  }

  // Kirim data ke MQTT
  client.publish("esp32/temperature", String(temp).c_str());
  client.publish("esp32/humidity", String(humi).c_str());

  delay(5000); // Kirim data setiap 5 detik
}

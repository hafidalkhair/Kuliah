#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

// Konfigurasi pin dan sensor
#define DHTPIN 4
#define DHTTYPE DHT11
#define LED_PIN 13

// Informasi jaringan WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Informasi server MQTT
const char* mqtt_server = "mqtt.esp32.my.id";
const int mqtt_port = 7931;
const char* mqtt_user = "tamu";
const char* mqtt_pass = "tamu2024";

// Objek WiFi dan MQTT
WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

// Fungsi untuk menghubungkan ke WiFi
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

// Fungsi untuk menghubungkan ke broker MQTT
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

// Fungsi setup
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

// Fungsi utama (loop)
void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" ºC | Humidity: ");
  Serial.println(humidity);

  // Kontrol LED berdasarkan suhu
  if (temperature > 30.0) {
    digitalWrite(LED_PIN, HIGH);
  } else if (temperature < 25.0) {
    digitalWrite(LED_PIN, LOW);
  }

  // Kirim data ke topik MQTT
  client.publish("esp32/temperature", String(temperature).c_str());
  client.publish("esp32/humidity", String(humidity).c_str());

  delay(5000); // Kirim setiap 5 detik
}

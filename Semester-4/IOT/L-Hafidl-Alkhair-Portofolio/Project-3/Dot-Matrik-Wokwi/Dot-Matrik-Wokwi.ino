#include <WiFi.h>
#include <PubSubClient.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Dot matrix configuration
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 5
MD_Parola disp = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// WiFi credentials (gunakan WiFi di Wokwi)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT broker settings
const char* mqtt_server = "mqtt.esp32.my.id";
const int mqtt_port = 7931;
const char* mqtt_user = "tamu";
const char* mqtt_pass = "tamu2024";

// Topic untuk menerima pesan teks
const char* topic_subscribe = "display/text";

WiFiClient espClient;
PubSubClient client(espClient);

String message = "";

void connectWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

void callback(char* topic, byte* payload, unsigned int length) {
  message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Received message: ");
  Serial.println(message);

  disp.displayClear();
  disp.displayText(message.c_str(), PA_RIGHT, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  disp.displayReset();
}

void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
      client.subscribe(topic_subscribe);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  disp.begin();
  disp.setIntensity(15);
  disp.displayClear();

  connectWiFi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  if (disp.displayAnimate()) {
    // loop scroll
    disp.displayReset();
  }
}

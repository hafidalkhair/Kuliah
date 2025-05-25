#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "HOMESTAY";
const char* password = "harihari";
const char* mqtt_server = "esp32.my.id";
const int mqtt_port = 1174;

// MQTT topics
const char* topic_subscribe = "OnOff";
const char* topic_publish = "kirimHelloWorld1";

// WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// Pin untuk lima LED dan buzzer
#define LED1 2
#define LED2 4
#define LED3 16
#define LED4 17
#define LED5 18
#define BUZZER 19

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 1000) {  // Timeout 10 detik
    delay(5000);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to WiFi. Restarting...");
    ESP.restart();  // Restart jika WiFi gagal tersambung
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  // Baca payload dan ubah menjadi string
  String command = "";
  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }
  Serial.println(command);

  if (command.length() == 1) {  // Pastikan hanya memproses payload 1 karakter
    char cmd = command[0];
    switch (cmd) {
      case '1': digitalWrite(LED1, HIGH); break;
      case '2': digitalWrite(LED2, HIGH); break;
      case '3': digitalWrite(LED3, HIGH); break;
      case '4': digitalWrite(LED4, HIGH); break;
      case '5': digitalWrite(LED5, HIGH); break;
      case '6': tone(BUZZER, 1000); break;  // Nyalakan buzzer dengan frekuensi 1000 Hz
      case '0':  // Matikan semua LED dan buzzer
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, LOW);
        noTone(BUZZER);
        break;
      default:
        Serial.println("Unknown command!");
    }
  } else {
    Serial.println("Invalid payload length!");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish(topic_publish, "ESP32 connected");
      client.subscribe(topic_subscribe);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  // Inisialisasi semua pin LED dan buzzer sebagai output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    setup_wifi();  // Coba sambung ulang jika WiFi terputus
  }

  if (!client.connected()) {
    reconnect();  // Coba sambung ulang jika MQTT terputus
  }

  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 200) {  // Kirim pesan setiap 2 detik
    lastMsg = now;
    snprintf(msg, MSG_BUFFER_SIZE, "hello world #%d", value++);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(topic_publish, msg);
  }
}

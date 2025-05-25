#include <WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "yagitu";
const char* password = "tidaktahu";
const char* mqtt_server = "mqtt-dashboard.com";

char* topic_subscribe = "LampuOnJoll";
char* topic_publish = "kirimHelloWorld1";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

#define LED1 2          // Pin untuk LED pertama
#define LED2 4          // Pin untuk LED kedua (ubah sesuai dengan pin yang digunakan)

void setup_wifi() {

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Memeriksa payload untuk mengontrol LED
  if ((char)payload[0] == '1') {
    digitalWrite(LED1, HIGH);    // Nyalakan LED 1
  } 
  else if ((char)payload[0] == '2') {
    digitalWrite(LED2, HIGH);    // Nyalakan LED 2
  } 
  else if ((char)payload[0] == '3') {
    digitalWrite(LED1, LOW);     // Matikan LED 1
    digitalWrite(LED2, LOW);     // Matikan LED 2
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish(topic_publish, "hello world");
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
  pinMode(LED1, OUTPUT);     // Inisialisasi pin LED pertama sebagai output
  pinMode(LED2, OUTPUT);     // Inisialisasi pin LED kedua sebagai output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf(msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(topic_publish, msg);
  }
}

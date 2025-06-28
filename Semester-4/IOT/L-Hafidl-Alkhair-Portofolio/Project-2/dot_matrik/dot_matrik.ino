#include "MD_Parola.h"
#include "MD_MAX72xx.h"
#include "SPI.h"
#include "DHT.h"

// Konfigurasi dot matrix
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 5
MD_Parola disp = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Konfigurasi DHT11
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Variabel
String message = "";
int displayState = 0;
unsigned long lastUpdate = 0;
unsigned long interval = 5000; // waktu ganti pesan

bool dhtConnected = false;

void setup() {
  disp.begin();
  disp.setIntensity(15);
  disp.displayClear();

  dht.begin();
  delay(1000); // waktu inisialisasi sensor

  // Coba baca pertama kali untuk cek koneksi
  float t = dht.readTemperature();
  if (!isnan(t)) {
    dhtConnected = true;
    message = "Humadity & Temperature";
  } else {
    dhtConnected = false;
    message = "Sensor DHT tidak terbaca";
  }

  disp.displayText(message.c_str(), PA_RIGHT, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  if (disp.displayAnimate()) {
    if (!dhtConnected) {
      // Jangan lanjut kalau sensor tidak terbaca
      disp.displayText("Sensor DHT tidak terbaca", PA_RIGHT, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
      disp.displayReset();
      delay(3000); // beri jeda sebelum ulangi lagi
      return;
    }

    unsigned long now = millis();
    if (now - lastUpdate > interval) {
      lastUpdate = now;

      if (displayState == 0) {
        message = "Humadity & Temperature";
        displayState = 1;
      } else if (displayState == 1) {
        float temp = dht.readTemperature();
        if (isnan(temp)) temp = 0;
        message = "T: " + String(temp) + " C";
        displayState = 2;
      } else {
        float hum = dht.readHumidity();
        if (isnan(hum)) hum = 0;
        message = "S: " + String(hum) + " %";
        displayState = 0;
      }

      disp.displayText(message.c_str(), PA_RIGHT, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
      disp.displayReset();
    }
  }
}

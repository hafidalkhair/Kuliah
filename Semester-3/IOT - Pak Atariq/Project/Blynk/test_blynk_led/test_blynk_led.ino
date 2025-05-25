#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Pin DHT11 terhubung
#define DHTPIN 4       // Pin digital 4 pada Arduino Uno
#define DHTTYPE DHT11  // Jenis sensor DHT11

// Inisialisasi sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void sendSensorData() {
  // Baca data suhu dan kelembapan
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Periksa apakah pembacaan berhasil
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Tampilkan data suhu dan kelembapan di Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");
}

void setup() {
  // Inisialisasi komunikasi Serial
  Serial.begin(9600);  // Arduino Uno biasanya menggunakan baud rate 9600
  dht.begin();         // Inisialisasi sensor DHT
  delay(2000);         // Tunggu sensor siap
}

void loop() {
  sendSensorData();    // Kirim data sensor ke Serial Monitor
  delay(2000);         // Tunggu 2 detik sebelum pembacaan berikutnya
}

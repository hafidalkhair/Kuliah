// Mendefinisikan pin LED
int ledPin = 13;

void setup() {
  // Mengatur pin LED sebagai output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Menyalakan LED
  digitalWrite(ledPin, HIGH);
  // Menunggu 1 detik
  delay(1000);
  // Mematikan LED
  digitalWrite(ledPin, LOW);
  // Menunggu 1 detik
  delay(1000);
}

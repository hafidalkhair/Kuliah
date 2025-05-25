// Define the pins
const int soundSensorPin = A0;   // Analog pin connected to the sound sensor
const int buzzerPin = 9;         // PWM pin connected to the buzzer

// Sound threshold for activation
const int soundThreshold = 500;  // Adjust this threshold based on testing

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);

  // Initialize the pins
  pinMode(soundSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Make sure the buzzer is off initially
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  // Read the analog value from the sound sensor
  int soundLevel = analogRead(soundSensorPin);
  
  // Debugging: Print the sound level to the Serial Monitor
  Serial.println("Sound Level: " + String(soundLevel));

  // Check if the sound level exceeds the threshold
  if (soundLevel > soundThreshold) {
    // Turn on the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(500);  // Keep the buzzer on for 500 ms (adjust as needed)
    
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Short delay before next reading
  delay(100);  // Adjust this delay based on your application requirements
}

#define VIBRATION_PIN 2   // Pin connected to SW-420 digital output
#define LED_PIN 13        // Optional: LED pin for indication

void setup() {
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int vibration = digitalRead(VIBRATION_PIN);

  if (vibration == HIGH) {
    Serial.println("Impact detected! Possible accident.");
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    delay(500); // Optional: delay to debounce
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
  }
}

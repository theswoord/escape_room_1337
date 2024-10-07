const int ledPin = 9; // Pin connected to the LED
char receivedChar;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  pinMode(ledPin, OUTPUT); // Set LED pin as output
}

void loop() {
  if (Serial.available()) {
    receivedChar = Serial.read(); // Read the incoming byte
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH); // Turn the LED on
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW); // Turn the LED off
    }
  }
}

#include <Servo.h>

Servo myservo;

int photo = 7;        // Pin connected to the light sensor
int speed = 0;        // Initial speed
int maxSpeed = 180;   // Maximum speed (adjust as necessary)
int increment = 5;    // Speed increment per loop

void setup() {
  Serial.begin(9600);
  pinMode(photo, INPUT);
  myservo.attach(6); // Attach the servo to pin 6
  myservo.write(0);   // Start at position 0 (stop)
}

void loop() {
  if (digitalRead(photo) == LOW) { // Change to HIGH for light detected
    Serial.println("Light detected - increasing speed");
    
    // Increase speed until it reaches maxSpeed
    if (speed < maxSpeed) {
      speed += increment; // Increment the speed
      if (speed > maxSpeed) {
        speed = maxSpeed; // Cap speed at maxSpeed
      }
    }

    myservo.write(speed); // Set the servo to the current speed
  } else {
//    Serial.println("No light detected - stopping");
    myservo.write(0); // Stop the servo when no light is detected
    speed = 0;        // Reset speed to 0
  }
  delay(100); // Short delay for responsiveness
}

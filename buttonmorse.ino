int button = 8;
int buttonState = 0;  // variable for reading the pushbutton status
int current; // Current state of the button
// (LOW is pressed b/c i'm using the pullup resistors)
int count; // How long the button was held (secs)
byte previous = LOW;
int lastButtonState = 0;
unsigned long firstTime; // how long since the button was first pressed
long lastReleaseTime = 0;
const long pressGap = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  Serial.println("Started");
}

void loop() {
  //  buttonState = digitalRead(button);
  //
  //  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //  if (buttonState == HIGH) {
  //    // turn LED on:
  ////    digitalWrite(ledPin, HIGH);
  //Serial.println("wrkt");
  //  } else {
  //    // turn LED off:
  //    Serial.println("tl9t");
  ////    digitalWrite(ledPin, LOW);
  //  }
  //delay(100);
  out();
}

void spacex(long diff)
{
  if (diff > 250)
  {
    Serial.print(' ');
  }
}

void out()
{
  buttonState = digitalRead(button);
  if (buttonState == LOW && lastButtonState == HIGH) {
    long diff = millis() - firstTime;

    long gap = millis() - lastReleaseTime;

    // Print a space if the gap is longer than the defined threshold
    if (gap > pressGap) {
      Serial.print(' '); // Print space if the gap is significant
    }
    // Print based on how long the button was pressed
    if (diff > 200) {
      //      spacex(diff);
      Serial.print('_');
    } else {
      //      spacex(diff);
      Serial.print('.');
    }
    //    spacex(diff);
    lastReleaseTime = millis();
    //    Serial.print(' ');
    // Reset firstTime for the next button press
    firstTime = 0;
  }

  // If the button is pressed, record the time
  if (buttonState == HIGH) {
    if (firstTime == 0) {
      firstTime = millis(); // Record the time when button is first pressed
    }
  }

  lastButtonState = buttonState; // Update the last button state
  delay(50); // Debounce delay
  //  Serial.println(buttonState);
  //  if (buttonState == HIGH && previous == LOW && millis() - firstTime > 200) {
  ////    Serial.println('_');
  //    firstTime = millis();
  //  }
  ////  Serial.println(firstTime);
  //  // Notice that we check if the the button has been held for at least 500 ms
  //  // This is to debounce the input (basically make sure we get the steady state of the button)
  //  if (buttonState == HIGH && ((millis() - firstTime) % 1000) < 20 && millis() - firstTime > 50) {
  //    Serial.println('-');
  //    count++; // and add 1 to the counter
  //  }
  //  // reset the counter if the button is not pressed
  //  if (buttonState == LOW) {
  ////    Serial.println('-');
  //    count = 0;
  //  }

  //    if (buttonState == HIGH) {
  //      Serial.println('.');
  //            } else {
  //        Serial.print('-');
  //  }
  //  return ' ';
}

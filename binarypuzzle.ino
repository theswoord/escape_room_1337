const int buttonZero = 7;  // Pin for the button 0
const int buttonOne = 8;  // Pin for the button 1
const int ledPinZero = 12; // LED pin 0
const int ledPinOne = 13; // LED pin 1
int inputSequence[5][8] = {0};  // Array to store player's binary input
int currentIndex = 0;  // Tracks player's current input position index
int currentArray = 0;  // Tracks player's current input position array
unsigned long buttonPressStart0 = 0;
unsigned long buttonPressStart1 = 0;
const int correctSequence[5][8] = {
	{0, 1, 0, 0, 1, 1, 0, 0}, //	a
	{0, 1, 1, 0, 1, 0, 0, 1}, //	X
	{0, 1, 1, 0, 0, 1, 1, 0}, //	7
	{0, 1, 1, 0, 0, 1, 0, 1}, //	;
	{0, 0, 1, 0, 0, 0, 0, 1}  //	!
};  // Correct binary word

enum GameState { WAITING, CHECKING, SUCCESS, RESET }; // Define states
GameState state = WAITING; // Initial state

void setup() {
  pinMode(buttonZero, INPUT_PULLUP); // Set the button as input with pull-up for 0
  pinMode(buttonOne, INPUT_PULLUP); // Set the button as input with pull-up for 1
  pinMode(ledPinZero, OUTPUT);        // Set the LED pin as output 0
  pinMode(ledPinOne, OUTPUT);        // Set the LED pin as output 1
  Serial.begin(9600);             // Start serial communication at 9600 baud rate
}

void display() {
  digitalWrite(ledPinZero, LOW);
  digitalWrite(ledPinOne, LOW);
  delay(200);
  digitalWrite(ledPinZero, HIGH);
  digitalWrite(ledPinOne, HIGH);
  delay(200);
  int i = 0;
  int j = 0;
//   while(i < 5){
// //    Serial.print(correctSequence[i][j];
//     while(j < 8){
      
//       Serial.print(correctSequence[i][j]);
//       j++;
//       }
//       i++;
//       j=0;
//     }
Serial.println("LIFE!");
state = WAITING;
//  Serial.print(correctSequence[i][j];
  
}

bool checkInput() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      if (inputSequence[i][j] != correctSequence[i][j]){
        return false;
      }
    }
  }
  return true;
}

void resetGame() {
  currentIndex = 0; // Resetting index to 0
  currentArray = 0; // Resetting current array
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      inputSequence[i][j] = 0; // Clear the input sequence
    }
  }
  
  // Flashing LEDs to indicate reset
  for (int i = 0; i < 7; i++) {
    digitalWrite(ledPinOne, LOW);
    digitalWrite(ledPinZero, HIGH);
    delay(200);
    digitalWrite(ledPinZero, LOW);
    digitalWrite(ledPinOne, HIGH);
    delay(200);
  }
  
  Serial.println("Game reset");
  state = WAITING; // Transition back to WAITING state
}

bool buttonPressed = false; // Flag to track button state

void loop() {
  switch (state) {
    case WAITING:
      if (!digitalRead(buttonZero) && !digitalRead(buttonOne)) {
        resetGame();
        break;
      }

      // Check if buttonZero is pressed
      if (!digitalRead(buttonZero) && !buttonPressed) {
        digitalWrite(ledPinOne, LOW);
        digitalWrite(ledPinZero, HIGH);
        inputSequence[currentArray][currentIndex] = 0;
        // Serial.println("0");
        buttonPressStart0 = millis();
        buttonPressStart1 = 0;
        buttonPressed = true; // Set flag to true
        delay(500);
      }
      // Check if buttonOne is pressed
      else if (!digitalRead(buttonOne) && !buttonPressed) {
        digitalWrite(ledPinZero, LOW);
        digitalWrite(ledPinOne, HIGH);
        inputSequence[currentArray][currentIndex] = 1;
        // Serial.println("1");
        buttonPressStart1 = millis();
        buttonPressStart0 = 0;
        buttonPressed = true; // Set flag to true
        delay(500);
      }
      // Handle button release
      else {
        // Check if buttons are released
        if (digitalRead(buttonZero)) {
          digitalWrite(ledPinZero, LOW);
          if (buttonPressed) {
            buttonPressed = false; // Reset flag when buttonZero is released
          }
        }
        if (digitalRead(buttonOne)) {
          digitalWrite(ledPinOne, LOW);
          if (buttonPressed) {
            buttonPressed = false; // Reset flag when buttonOne is released
          }
        }
        break;
      }

      // Process next index only if a button was pressed
      currentIndex++;
      if (currentIndex == 8) {
        // for(int i = 0 ; i < 8 ; i++)
        // {
        //   Serial.print(inputSequence[currentArray][i]);
        // }
        currentIndex = 0;

        currentArray++;
      }
      if (currentArray == 5) {
        // Serial.println("CHECKINGSTAUS");
        state = CHECKING;
      }
      break;

    case CHECKING:
  //   Serial.println("hadchi li dkhel\n");
  //     for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     Serial.print(inputSequence[i][j]); // Clear the input sequence
  //   }
  // }
  //   Serial.println("hadchi li dkhel\n");
  //     for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j < 8; j++) {
  //     Serial.print(correctSequence[i][j]); // Clear the input sequence
  //   }
  // }
  //   Serial.println("hadchi li khasso ikoun\n");
      if (checkInput()) {
        // Serial.println("WARB7TIII");
        state = SUCCESS;
      } else {
        resetGame();
        break;
      }
      break;

    case SUCCESS:
      display();
      break;
  }
}
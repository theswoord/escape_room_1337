This repository contains the code and documentation for two distinct puzzles designed and implemented for an escape room. Each puzzle provides a unique challenge for players to solve.
🧩 Puzzle 1: Binary Word Converter (Arduino)

This puzzle challenges players to input a binary sequence using two buttons, which is then converted into a word. The correct word acts as a clue or solution for the escape room.
📜 How it Works

Players interact with two physical buttons, representing '0' and '1'. They must press these buttons in a specific sequence to form a binary number. The Arduino reads this sequence, converts the binary input into a decimal number, and then maps that decimal number to a predefined word. If the sequence is correct, the associated word is revealed (e.g., via an LCD screen, LED array, or serial output to another system).
🛠️ Components Used

    Arduino Board: (Arduino Uno)

    Momentary Push Buttons: Two buttons for binary input.

    Resistors: For pull-up/pull-down on button inputs (if not using internal pull-ups).

    Display Mechanism: serial communication to a connected device

    Wiring: Jumper wires.

⚙️ Setup and Code

    Hardware Connection:

        Connect the two push buttons to digital input pins on your Arduino (e.g., Pin 2 and Pin 3).

        Ensure proper pull-up or pull-down resistors are used for stable readings, or enable internal pull-up resistors in your code.

        Connect your chosen display mechanism (LCD, LEDs) to the appropriate Arduino pins as per its documentation.

🧩 Puzzle 2: RFID Sequence Password (Raspberry Pi)

This puzzle requires players to scan a sequence of specific RFID cards in the correct order to reveal a password.
📜 How it Works

Players are presented with a set of RFID cards. They must identify the correct cards and scan them one by one in a predetermined order using an RFID reader connected to a Raspberry Pi. The Python script on the Raspberry Pi validates the sequence of scanned cards. Upon successful completion, a password or clue is revealed (e.g., displayed on screen, spoken via text-to-speech, or triggers an external device).
🛠️ Components Used

    Raspberry Pi Board: (Raspberry Pi 4)

    RFID Reader Module: (RC522 module)

    RFID Cards/Tags: Multiple cards with unique UIDs (Unique Identifiers).

    Jumper Wires: For connecting the RFID reader to the Raspberry Pi's GPIO pins.

    Power Supply: For the Raspberry Pi.

    Display mechanism: external terminal on Mac using SSH

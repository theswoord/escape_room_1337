import serial
import time
from mfrc522 import SimpleMFRC522

# Initialize RFID reader
reader = SimpleMFRC522()

# Initialize serial communication with Arduino
arduino = serial.Serial('/dev/ttyACM0', 9600)  # Adjust the port as necessary
time.sleep(2)  # Wait for the serial connection to initialize
delay = 1

try:
    while True:
        print("Place your card to read")
        id, text = reader.read()  # Read the card
        print("ID: ", id)
        if id == 563757338655:
            delay = 5
        elif id == 819239132520:
            delay = 10
        else:
            delay = 1
        # Send '1' to Arduino to turn on the LED
        arduino.write(b'1')
        time.sleep(delay)  # Keep the LED on for a second
        
        # Send '0' to Arduino to turn off the LED
        arduino.write(b'0')
        time.sleep(1)  # Wait before reading again

except KeyboardInterrupt:
    print("Program stopped")
finally:
    arduino.close()

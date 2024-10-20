import serial
import signal
import sys

def signal_handler(sig, frame):
    ser.close()
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

# Initialize the serial connection
ser = serial.Serial('/dev/ttyACM0', 9600)

try:
    while True:
        line = ser.readline().decode("iso-8859-1").strip()  # Decode and strip whitespace
        print(line)
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    ser.close()

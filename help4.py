import RPi.GPIO as GPIO
import vlc
import time
from mfrc522 import SimpleMFRC522

# Initialize RFID reader and VLC player
rfid = SimpleMFRC522()
media_path = "/home/nabil/Desktop/rfid/applause.mp3"
p = vlc.MediaPlayer(media_path)

# Variables to manage RFID reading
audio_playing = False

try:
    while True:
        idd, _ = rfid.read()
        
        if idd != 0 and not audio_playing:  # Only process if audio is not playing
            print(f"Detected RFID: {idd}")
            print("Playing audio...")
            p.stop()  # Ensure no audio is playing before starting
            p.play()  # Play the audio
            audio_playing = True  # Set the flag to indicate audio is playing
            
            # Allow some time for the media to load
            time.sleep(0.5)  # Short wait to allow media to load
            
            # Attempt to get the duration
            retries = 3
            duration = -1
            while retries > 0:
                duration = p.get_length() / 1000  # Convert milliseconds to seconds
                if duration > 0:  # Check if the duration is valid
                    break
                print("Error: Unable to retrieve audio duration. Retrying...")
                time.sleep(0.5)  # Wait a bit before retrying
                retries -= 1
            
            if duration > 0:  # Only sleep if duration is valid
                time.sleep(duration)
            else:
                print("Failed to retrieve audio duration after multiple attempts.")
            
            audio_playing = False  # Reset the flag after audio finishes

except KeyboardInterrupt:
    print("Program ended by user")
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    p.stop()  # Ensure player is stopped on exit
    GPIO.cleanup()

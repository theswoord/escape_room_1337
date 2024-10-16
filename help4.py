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

def card_check(arr):
    correct = ["639310570126", "913448570801"] 
    return arr == correct



try:
    while True:
        print("Place the first card near the reader...")
        uid1, _ = rfid.read()
        uid1_str = str(uid1).strip()  # Convert UID to string and remove any whitespace
        print(f"First card ID: {uid1_str}")

        time.sleep(2)  # Delay before reading the second card
        print("Place the second card near the rfid...")
        uid2, _ = rfid.read()
        uid2_str = str(uid2).strip()  # Convert UID to string and remove any whitespace
        print(f"Second card ID: {uid2_str}")

        # Check the UIDs using the card_check function
        if card_check([uid1_str, uid2_str]):
            print("WOOHOO you won!")
            break  # Exit the loop if the IDs are correct
        else:
            print("The IDs are NOT in the correct order. Please try again.")
            # print(p.get_length())
            # Play the sound
            p = vlc.MediaPlayer(media_path)
            p.play()
            # Sleep until the sound finishes
            time.sleep(10)  # Convert milliseconds to seconds

        # if idd != 0 and not audio_playing:  # Only process if audio is not playing
        #     print(f"Detected RFID: {idd}")
        #     print("Playing audio...")
        #     p.stop()  # Ensure no audio is playing before starting
        #     p.play()  # Play the audio
        #     audio_playing = True  # Set the flag to indicate audio is playing
            
        #     # Allow some time for the media to load
        #     time.sleep(0.5)  # Short wait to allow media to load
            
        #     # Attempt to get the duration
        #     retries = 3
        #     duration = -1
        #     while retries > 0:
        #         duration = p.get_length() / 1000  # Convert milliseconds to seconds
        #         if duration > 0:  # Check if the duration is valid
        #             break
        #         print("Error: Unable to retrieve audio duration. Retrying...")
        #         time.sleep(0.5)  # Wait a bit before retrying
        #         retries -= 1
            
        #     if duration > 0:  # Only sleep if duration is valid
        #         time.sleep(duration)
        #     else:
        #         print("Failed to retrieve audio duration after multiple attempts.")
            
        #     audio_playing = False  # Reset the flag after audio finishes

except KeyboardInterrupt:
    print("Program ended by user")
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    p.stop()  # Ensure player is stopped on exit
    GPIO.cleanup()

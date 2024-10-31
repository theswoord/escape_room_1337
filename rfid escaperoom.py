import RPi.GPIO as GPIO
import vlc
import time
from colorama import Fore, Back, Style
from mfrc522 import SimpleMFRC522
from art import *
import os
import sys
import signal

rfid = SimpleMFRC522()
media_lose = "/home/nabil/Desktop/eskip/failwitheffect.mp3"
media_win = "/home/nabil/Desktop/eskip/winwitheffects.mp3"

p = vlc.MediaPlayer(media_lose)

audio_playing = False

def card_check(arr):
    correct = ["639310570126", "913448570801"] 
    return arr == correct

def sigint_handler(signum, frame):
    print(Fore.RED + "There is no escape!" + Fore.RESET)
def sigusr1_handler(signum, frame):
    print(Fore.YELLOW + "Exiting the program..." + Fore.RESET)
    sys.exit(0)
signal.signal(signal.SIGINT, sigint_handler)
signal.signal(signal.SIGTSTP, sigusr1_handler)

try:
    while True:
        print("Welcome to the death race")
        print("Who do you think won the race ?")
        uid1, _ = rfid.read()
        uid1_str = str(uid1).strip()
        print(Fore.YELLOW + 'hummm I See !' + Fore.RESET)

        time.sleep(2)
        print("And who came 2nd place ?")
        uid2, _ = rfid.read()
        uid2_str = str(uid2).strip()


        
        if card_check([uid1_str, uid2_str]):
            print(Back.GREEN+"\t\tHAHAHA What a worthy person !"+ Back.RESET)
            print("The spell shall be :")
            p = vlc.MediaPlayer(media_win)
            p.play()
            print(Fore.GREEN + "\"---- ----- you mei\"" + Fore.RESET)
            time.sleep(5)
            break
        else:
            print(Back.RED + "====================================================" + Back.RESET)
            print(Fore.RED+"\t\tThis is so wrong ... !!"+Fore.RESET)
            print(Back.RED + "====================================================" + Back.RESET)
            p = vlc.MediaPlayer(media_lose)
            p.play()
            time.sleep(5)
            os.system('clear')

except Exception as e:
    print(f"An error occurred: {e}")
finally:
    p.stop()
    GPIO.cleanup()


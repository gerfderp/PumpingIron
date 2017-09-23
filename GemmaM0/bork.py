from touchio import *
from digitalio import *
from analogio import *
from board import *
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import dotstar
import time
from adafruit_hid.mouse import Mouse

m = Mouse()

led = DigitalInOut(D13)
led.direction = Direction.OUTPUT

touch2 = TouchIn(A2)


isThisOn = False
while True:
    print ("touch2" + str(touch2.value))
    if (touch2.value):
        isThisOn = not isThisOn
        print ("running: " + str(isThisOn))

    led.value = isThisOn
    if (isThisOn) :
        m.click(Mouse.LEFT_BUTTON)
        time.sleep(0.5)
        m.release_all()
        time.sleep(0.5)
    else:
        time.sleep(0.5)

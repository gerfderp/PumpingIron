/*
ProTrinketMouseRandom example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries

Please use library TrinketKeyboard for the ATtiny85 based Trinket

Version 1.0  2015-01-03 Initial Version derived from TrinketMouseExample  Mike Barela

This example simply starts a mouse and randomly moves it around, while clicking random buttons
*/

#include <ProTrinketMouse.h>

const int switchPin = 9; // switch to turn on and off mouse control
const int ledPin = 3; // Mouse control LED 
boolean mouseIsActive = false;      // whether or not to control the mouse
int lastSwitchState = LOW; // previous switch state
void setup()
{
  pinMode(switchPin, INPUT_PULLUP); // the switch pin
   pinMode(ledPin, OUTPUT); // the LED pin  
  TrinketMouse.begin();
}

void loop()
{

  int switchState; // State of the mouse enable/disable button
    switchState = digitalRead(switchPin);  // read the mouse disable switch
  // if it's changed and it's high, toggle the mouse state
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
      digitalWrite(ledPin, mouseIsActive);   // toggle LED to indicate mouse state
    } 
}
lastSwitchState = switchState;    // save switch state for next comparison

//  TrinketMouse.move(random(), random(), random(), random() & 0x07);
if (mouseIsActive) {
//  TrinketMouse.move(random(2000,2005), random(2000,2005), 0, MOUSEBTN_LEFT_MASK);
  TrinketMouse.move(0,0,0,MOUSEBTN_LEFT_MASK); 
  delay(50);
  TrinketMouse.move(0,0,0,0);
  delay(50); 
}

}

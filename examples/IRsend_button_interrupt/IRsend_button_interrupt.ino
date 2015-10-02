#include <IRremote.h>

const int buttonPin = 8;
int buttonVal = LOW;

IRsend irsend;
int sending = 0x83204D4A;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  enablePinInterrupt(buttonPin);
}

void loop() {
  // put your main code here, to run repeatedly
}


void button_press() { 
  irsend.sendNEC(sending, 32);
  sending += 1;
}

void enablePinInterrupt(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  if(digitalRead(buttonPin)) {  button_press(); }
}


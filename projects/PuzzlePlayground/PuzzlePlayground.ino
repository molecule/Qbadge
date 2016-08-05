/*
 * Copyright (c) 2015, 2016 Molly Nicholas
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * (subject to the limitations in the disclaimer below) provided that the following conditions are
 * met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 * and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 * and the following disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Qbadge nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE. THIS
 * SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//******* Button *********//
const int buttonPin = 8;  // #6 on port D, #8 on port B

//******** Neopixel ***********//
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIXEL_PIN 4
#define NUM_LEDS 18
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int brightness = 90;
int delayVal = 50;
int pulseDelay = 20;
int DISPLAY_DELAY = 5000;//ms

//******** IR Receive **********//
#include <IRremote.h>

// We need to use the 'raw' pin reading methods because timing is very important here 
// and the digitalRead() procedure is slower!
#define IRrx_PIN_VECTOR PIND
#define IRrx 5

#define MAXPULSE    5000  // the maximum pulse we'll listen for - 5 milliseconds 
#define NUMPULSES    50  // max IR pulse pairs to sample
#define RESOLUTION     2  // // time between IR measurements

// we will store up to 50 pulse pairs (this is -a lot-)
uint16_t pulses[NUMPULSES][2]; // pair is high and low pulse
uint16_t currentpulse = 0; // index for pulses we're storing
uint32_t irCode = 0;

//********* IR Send *********//
const uint32_t IR_PUZZLE_GUESS     = 0x8322FFFF;
const uint32_t IR_REMOTE_POWER     = 0x8322A15E;
const uint32_t IR_PUZZLE_THREE     = 0x8322A659;
const uint32_t IR_PUZZLE_ONE       = 0x8322AE51;
const uint32_t IR_PUZZLE_TWO       = 0x8322A25D;
const uint32_t IR_REMOTE_V_DOWN    = 0x8322A35C;
const uint32_t IR_REMOTE_MODE      = 0x8322B24D;
const uint32_t IR_REMOTE_REWIND    = 0x8322A55A;
const uint32_t IR_REMOTE_PLAY      = 0x8322B04F;
const uint32_t IR_REMOTE_FORWARD   = 0x8322A45B;

const uint32_t IR_HEADER = 0x83220000;

IRsend irsend;
uint32_t sending = IR_PUZZLE_GUESS;


void setup() {
  // Buttons setup
  pinMode(buttonPin, INPUT);
  enablePinInterupt(buttonPin);

  // Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

/* When you're ready to try your answer to the first puzzle, just uncomment the line
 * of code that says "puzzleOne()". Once you upload your solution to the badge, you can
 * head over to Puzzle Station #1 to test it out. If you got it right, you'll see a hint
 * for Puzzle #2, and you can move on to solving that one. Happy puzzling!
 */
void loop() {
  puzzleOne();
  //puzzleTwo();
  //puzzleThree();

}

//**********************************************************************************//
//**********************************************************************************//
//*********************************** PUZZLE ONE ***********************************//
//**********************************************************************************//
//**********************************************************************************//

const uint16_t BIG_VALUE = 0x1DD7;
const uint8_t SOMEWHAT_BIG_VALUE = 0x17;
void puzzleOne() {
  uint8_t input_val = SOMEWHAT_BIG_VALUE;
  sending = IR_HEADER | buggy(input_val);
}

// Hmmmm something here doesn't look quite right...
uint16_t buggy(uint8_t input) {
  uint8_t constant_value = BIG_VALUE;
  uint8_t result = constant_value * input; //BUG BUG BUG
  return result; //OUTPUTS RED
}


//**********************************************************************************//
//**********************************************************************************//
//*********************************** PUZZLE TWO ***********************************//
//**********************************************************************************//
//**********************************************************************************//

// Maybe the correct answer to the first puzzle makes the badge glow BLUE.
// So the word "BLUE" is the hint to for the second puzzle. Imagine some ints:
// #define B = 2;
// #define C = 3;
// ...
// #define E = 7;
// ...
// etc with a lot of different letters. Their job is to find the "B", "L", "U", 
// and "E" and use those in puzzleTwo.
void puzzleTwo() {
  sending = IR_PUZZLE_GUESS;
}


//**********************************************************************************//
//**********************************************************************************//
//********************************** PUZZLE THREE **********************************//
//**********************************************************************************//
//**********************************************************************************//

void puzzleThree() {
  sending = IR_PUZZLE_GUESS;
}





/*
 * This method gets called when you press the button on the front of the badge.
 * It sends the 32-bit integer stored in "sending".
 */
void button_press() {
  irsend.sendNEC(sending, 32);
}

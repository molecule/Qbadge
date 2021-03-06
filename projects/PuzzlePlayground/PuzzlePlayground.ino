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
const uint32_t IR_PUZZLE_GUESS     = 0x8322A650;
const uint32_t IR_HEADER = 0x83220000;

IRsend irsend;
uint32_t sending = IR_PUZZLE_GUESS;


void setup() {
  Serial.begin(9600);

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

// Read through this code, and figure out what's going on.
// You'll need to make some changes (more info below) to get things to work...

const uint16_t BIG_VALUE = 0x1DD7;
const uint8_t SOMEWHAT_BIG_VALUE = 0x17;
void puzzleOne() {
  uint8_t input_val = SOMEWHAT_BIG_VALUE;
  sending = IR_HEADER | buggy(input_val);
}

// Hmmmm something doesn't look quite right here...
// Find the bug in this method, and fix it. Once you've created your solution,
// you can test it out by bringing your Qbadge over to Puzzle Station #1. Hit
// the button to see if you can get a new clue from the puzzle station!
uint16_t buggy(uint8_t input) {
  uint8_t constant_value = BIG_VALUE;
  uint8_t result = constant_value * input;
  return result;
}


//**********************************************************************************//
//**********************************************************************************//
//*********************************** PUZZLE TWO ***********************************//
//**********************************************************************************//
//**********************************************************************************//

// There are four parts to this puzzle. You'll have to solve all four to get the
// answer!

// Part 1: One of the constants in the "most beautiful equation"

// Part 2: Talk with a member of the campus team to get the next value.

// Part 3: I spy the next value somewhere in this room...

// Part 3: Puzzle Station #1 gave you some information...it's the same type
// of information as the previous three parts, and if you put it all together,
// it'll help you answer the question below.

// Put it all together to answer this question:
// What is the significance of this value as it relates to Grace Hopper?
// Something new was created by that magnificent Rear-Admiral. 
// Provide your guess in puzzleTwo() below,
// then head over to Puzzle Station #2 to test your answer! If you get it right,
// you'll see a new clue that will help you solve Puzzle #3.

//  !!! REMEMBER TO CHANGE WHICH PUZZLE YOU'RE CALLING IN LOOP() !!!
uint32_t A = 0xB;
uint32_t B = 0xD;
uint32_t C = 0x8;
uint32_t D = 0xF;
uint32_t E = 0x5;
uint32_t F = 0xB;
uint32_t G = 0x1;
uint32_t H = 0x4;
uint32_t I = 0xA;
uint32_t J = 0x6;
uint32_t K = 0x8;
uint32_t L = 0x2;
uint32_t M = 0x2;
uint32_t N = 0x9;
uint32_t O = 0x3;
uint32_t P = 0x2;
uint32_t Q = 0x7;
uint32_t R = 0xD;
uint32_t S = 0xD;
uint32_t T = 0x0;
uint32_t U = 0x2;
uint32_t V = 0xC;
uint32_t W = 0xE;
uint32_t X = 0x6;
uint32_t Y = 0x1;
uint32_t Z = 0xA;

void puzzleTwo() {
  sending = (A << 28) + (B << 24) + (C << 20) + (D << 16) + (E << 12) + (F << 8) + (G << 4) + (H);
}


//**********************************************************************************//
//**********************************************************************************//
//********************************** PUZZLE THREE **********************************//
//**********************************************************************************//
//**********************************************************************************//

// "Humans are allergic to change. They love to say 'we've always done it this way.'
// I try to fight that. _________________________________"
void puzzleThree() {
  sending = IR_PUZZLE_GUESS | officeFurniture();
}

// Grace Hopper had some very unique office furniture. Puzzle Station #2 was an
// abstract recreation of one of her most famous pieces. What information do
// you get from it? Return the value here.
uint32_t officeFurniture() {
  return 4;
}


/*
 * Don't change this method!
 *
 * This method gets called when you press the button on the front of the badge.
 * It sends the 32-bit integer stored in "sending".
 *
 * Don't change this method!
 */
void button_press() {
  irsend.sendNEC(sending, 32);
}

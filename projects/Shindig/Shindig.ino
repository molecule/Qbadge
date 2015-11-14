/*
 * Copyright (c) 2015 Molly Nicholas
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
 * Neither the name of Molly Nicholas nor the names of its contributors may be used to
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
int switchPin = 9;        // #9 on port B
int buttonVal = LOW;

const int partyPin = 6; // #6 on port D

//******* Bluetooth ******//
String AT_COMMAND_RX_SUCCESSFUL = String("OK");
String AT_COMMAND_RX_FAILED = String("ERROR");
String AT_CONNECTION_ESTABLISHED = String("CONNECTED");

//******** Questions *********** //
uint32_t QUESTION_MASK_ONE = 0x01;
uint32_t QUESTION_MASK_TWO = 0x02;
uint32_t QUESTION_MASK_THREE = 0x04;
uint32_t QUESTION_MASK_FOUR = 0x08;
uint32_t QUESTION_MASK_FIVE = 0x10;
uint32_t QUESTION_MASK_SIX = 0x20;
uint32_t QUESTION_MASK_SEVEN = 0x40;
uint32_t QUESTION_MASK_EIGHT = 0x80;
uint32_t QUESTION_MASK_NINE = 0x100;
uint32_t QUESTION_MASK_TEN = 0x200;
uint32_t QUESTION_MASK_ELEVEN = 0x400;
uint32_t QUESTION_MASK_TWELVE = 0x800;
uint32_t QUESTION_MASK_THIRTEEN = 0x1000;
uint32_t QUESTION_MASK_FOURTEEN = 0x2000;
uint32_t QUESTION_MASK_FIFTEEN = 0x4000;
uint32_t QUESTION_MASK_SIXTEEN = 0x8000;
uint32_t QUESTION_MASK_SEVENTEEN = 0x10000;
uint32_t QUESTION_MASK_EIGHTEEN = 0x20000;

uint32_t QUESTION_MASK_MAP[] = {
  0,
  QUESTION_MASK_ONE,
  QUESTION_MASK_TWO,
  QUESTION_MASK_THREE,
  QUESTION_MASK_FOUR,
  QUESTION_MASK_FIVE,
  QUESTION_MASK_SIX,
  QUESTION_MASK_SEVEN,
  QUESTION_MASK_EIGHT,
  QUESTION_MASK_NINE,
  QUESTION_MASK_TEN,
  QUESTION_MASK_ELEVEN,
  QUESTION_MASK_TWELVE,
  QUESTION_MASK_THIRTEEN,
  QUESTION_MASK_FOURTEEN,
  QUESTION_MASK_FIFTEEN,
  QUESTION_MASK_SIXTEEN,
  QUESTION_MASK_SEVENTEEN,
  QUESTION_MASK_EIGHTEEN
};

uint32_t questionsAnswered  = 0x0;

int NUM_QUESTIONS = 18;

//******** Neopixel *********** //
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIXEL_PIN 4
#define NUM_LEDS 18
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int brightness = 90;
int delayVal = 50;
int pulseDelay = 20;
int DISPLAY_DELAY = 5000;//ms

// Colors used in the random flash method.
// just add new {nnn, nnn, nnn}, lines. They will be picked out randomly
//                          R   G   B
uint8_t greenColors[][3] = {{30, 44, 0},    // leaf_green
                            {0, 24, 0},     // green
                            {0, 50, 24},    // sapphire
                            {12, 36, 23},   // mediumSeaGreen
                            {0, 50, 20},    // mediumSpringGreen
                            };
#define FAVCOLORS sizeof(greenColors) / 3

uint32_t white         = strip.Color(24, 24, 24);
uint32_t hot_pink      = strip.Color(48, 0, 24);
uint32_t light_blue    = strip.Color(0, 24, 24);
uint32_t bright_blue   = strip.Color(10, 24, 50);
uint32_t leaf_green    = strip.Color(30, 44, 0);
uint32_t purple        = strip.Color(17, 0, 44);
uint32_t yellowOrange  = strip.Color(44, 30, 0);
uint32_t sapphire      = strip.Color(0, 50, 24);
uint32_t green         = strip.Color(0, 24, 0);
uint32_t red           = strip.Color(24, 0, 0);
uint32_t blue          = strip.Color(0, 0, 24);
uint32_t salmon_pink   = strip.Color(236, 79, 100); 
uint32_t cream         = strip.Color(246, 216, 180);
uint32_t lavendar      = strip.Color(174, 113, 208);
uint32_t deep_purple   = strip.Color(91, 44, 86); 
uint32_t medium_purple = strip.Color(232, 100, 255);
uint32_t yellow        = strip.Color(200, 200, 20);
uint32_t mediumSeaGreen       = strip.Color(12, 36, 23);
uint32_t mediumSpringGreen    = strip.Color(0, 50, 20);
uint32_t lightGreen       = strip.Color(10, 50, 10);
uint32_t honeyDew         = strip.Color(30, 51, 30);
uint32_t rosyBrown        = strip.Color(38, 35, 35);
uint32_t thistle          = strip.Color(43, 24, 43);
uint32_t plum             = strip.Color(44, 20, 44);
uint32_t mediumOrchid     = strip.Color(44, 10, 44);
uint32_t mediumPurple     = strip.Color(44, 5, 44);
uint32_t mediumSlateBlue  = strip.Color(10, 10, 50);
uint32_t cornFlowerBlue   = strip.Color(5, 10, 50);
uint32_t skyBlue          = strip.Color(20, 30, 50);
uint32_t lightSkyBlue     = strip.Color(27, 30, 50);
uint32_t paleTurquoise    = strip.Color(20, 30, 48);
uint32_t powderBlue       = strip.Color(25, 35, 50);
uint32_t aquamarine       = strip.Color(25, 51, 42);
uint32_t turquoise        = strip.Color(13, 45, 42);
uint32_t mediumTurquoise  = strip.Color(14, 42, 41);
uint32_t lime  = strip.Color(0, 100, 0);

uint32_t pixelColors[NUM_LEDS];
uint32_t color;
float fadeRate = 0.96;

void (*functionPtrs[100])(); //the array of function pointers

//******** Debounce ************//
uint8_t switch_value;
uint8_t last_switch_value = 0;
uint32_t last_switch_change = 0;
uint32_t last_switch_debounce = 1000;

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
const uint32_t IR_REMOTE_POWER     = 0x8322A15E;
const uint32_t IR_REMOTE_SELECT    = 0x8322A659;
const uint32_t IR_REMOTE_MUTE      = 0x8322AE51;
const uint32_t IR_REMOTE_V_UP      = 0x8322A25D;
const uint32_t IR_REMOTE_V_DOWN    = 0x8322A35C;
const uint32_t IR_REMOTE_MODE      = 0x8322B24D;
const uint32_t IR_REMOTE_REWIND    = 0x8322A55A;
const uint32_t IR_REMOTE_PLAY      = 0x8322B04F;
const uint32_t IR_REMOTE_FORWARD   = 0x8322A45B;

IRsend irsend;
uint32_t sending = 0;
uint32_t header = 0x86000000; // 7 bits

uint8_t badge_id_me = 0x86; // 7 bits 135
uint8_t badge_id_you = 0xFF; // 0xFF no id received over IR
int mode = 0; // 0: answer questions, 1: send/receive IR

void setup() {
  //Set up on-board LED
  pinMode(13, OUTPUT);

  // Switch setup
  pinMode(switchPin, INPUT);
  last_switch_value = digitalRead(switchPin);
  switch_value = last_switch_value;

  if (last_switch_value == HIGH) {
    mode = 1;
    digitalWrite(13, HIGH);
  } else {
    mode = 0;
    digitalWrite(13, LOW);
  }

  pinMode(partyPin, INPUT);
  if (digitalRead(partyPin) == LOW) {
    mode = 2;
  }

  // Timer setup
  //timer0_init(); //1 ms timer
  timer1_init(100); // varable timer (1000 = 1 second)
  
  // Buttons setup
  pinMode(buttonPin, INPUT);
  enablePinInterupt(buttonPin);

  // Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  // initialize array to all zeros
  memset(pixelColors,0,sizeof(pixelColors));

  // initializes the array of function pointers.
  functionPtrs[0] = chase;
  functionPtrs[1] = chaseLime;
  functionPtrs[2] = chaseHotPink;
  functionPtrs[3] = chaseTurquoise;
  functionPtrs[4] = mediumOrchidAlternate;
  functionPtrs[5] = mediumOrchidBlueAlternate;
  functionPtrs[6] = chaseFlip;
  functionPtrs[7] = callSmiley;
  functionPtrs[8] = sparklePurple;
  functionPtrs[9] = white_flash_fade;
  functionPtrs[10] = glitter;
  functionPtrs[11] = rainbow_replace;
  functionPtrs[12] = rainbow_sparks;
  functionPtrs[13] = blue_sparkles;
  functionPtrs[14] = rainbowCycle;
  functionPtrs[15] = chaseYellowOrange;
  functionPtrs[16] = multi_color_blue_yellow;
  functionPtrs[17] = generate_rotation;
  functionPtrs[18] = multi_color_blue_green;
  functionPtrs[99] = red_flash;

  // Bluetooth setup
  bluetoothSetup();

  // IR setup
  sending = (header | (((uint32_t)badge_id_me)<<18));

  // Calculating your IR code based on your answers
  sending = sending | myAnswers();
  //bluetoothSerial.print("My IR code is ");
  //bluetoothSerial.println(sending, HEX);
  
  delay(100);
}

void loop() {
  if(mode == 0) {
    displayBasedOnInput( readFromBluetooth() );
  } else if (mode == 1) {
    ir_loop();
  } else if (mode == 2) {
    partyMode();
  }
}

void reportCorrectQuestions() {
  uint32_t temp = questionsAnswered;
  for(int i = 1; i <= NUM_QUESTIONS; i++) {
    if((temp & QUESTION_MASK_MAP[i]) == QUESTION_MASK_MAP[i]) {
      strip.setPixelColor(i-1, blue);
      strip.show();
      delay(20);
    }
  }
}

//################ CREATE YOUR OWN NEOPIXEL FUNCTION BY FILLING IN THIS METHOD! ################
// Note: you cannot edit the signature.
void newFunction() {

  
}
//#############################################################################################

void callFunction(int index) {
  (*functionPtrs[index])(); //calls the function at the index of `index` in the array
}

void button_press() {
  irsend.sendNEC(sending, 32);
}

void switch_it()
{
  uint8_t current_value = digitalRead(switchPin);
  
  if(last_switch_value != switch_value)
    last_switch_change = millis();
    
  if( ((millis()-last_switch_change) > last_switch_debounce)) {
    if(switch_value != current_value) {
      switch_value = current_value;

      // 0: answer questions, LED off, 1: send/receive IR, LED on,
      if(mode == 0) { 
        mode = 1; 
        if(badge_id_you!=0xFF) {
          char buffer[32];
          sprintf(buffer,"AT+QBEACON=%02X,%02X",badge_id_me, badge_id_you);
          Serial.println(buffer);
        }
        digitalWrite(13, HIGH);
      } 
      else { 
        mode = 0;
        Serial.println("AT+DATA");
        digitalWrite(13, LOW);
      }
    }
  }
  last_switch_value = switch_value;
}

void switchToPartyMode() {
  mode = 2;
}

void partyMode() {
  for (int i = 1; i <= NUM_QUESTIONS; i++) {
    callFunction(i);
    delay(DISPLAY_DELAY/3);
    callFunction(0);
    delay(30);
  }
}


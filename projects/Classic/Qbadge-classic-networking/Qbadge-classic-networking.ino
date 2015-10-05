//******* Button *********//
const int buttonPin = 8;
int buttonVal = LOW;

//******** Neopixel *********** //
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIXEL_PIN 4
#define NUM_LEDS 18
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int delayVal = 50;

uint32_t blue          = strip.Color(0, 0, 255);
uint32_t hot_pink      = strip.Color(48, 0, 24);
uint32_t magenta       = strip.Color(24, 0, 24);
uint32_t purple        = strip.Color(17, 0, 44);
uint32_t yellowOrange  = strip.Color(44, 30, 0);
uint32_t turquoise     = strip.Color(0, 50, 24);
uint32_t green         = strip.Color(0, 24, 0);

//******** IR Receive **********//
#include <IRremote.h>

// We need to use the 'raw' pin reading methods because timing is very important here 
// and the digitalRead() procedure is slower!
#define IRrx_PIN_VECTOR PIND
#define IRrx 5

#define MAXPULSE    5000  // the maximum pulse we'll listen for - 5 milliseconds 
#define NUMPULSES    50  // max IR pulse pairs to sample
#define RESOLUTION     2  // // time between IR measurements

// store up to 50 pulse pairs (this is -a lot-)
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

uint8_t badge_id_me = 0xb8; // 7 bits
uint8_t badge_id_you = 0xFF; // 0xFF no id received over IR

void setup() {
  // put your setup code here, to run once:
  // Button setup
  pinMode(buttonPin, INPUT);
  enablePinInterupt(buttonPin);
  
  // Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  // Bluetooth setup
  Serial.begin(9600);
  Serial.println("Hello...");
  delay(100);

  // IR setup
  sending = (header | (((uint32_t)badge_id_me)<<18));

  // Calculating your IR code based on your answers
  sending = sending | myAnswers();
  Serial.print("My IR code is ");
  Serial.println(sending, HEX);
}

void loop() {
  
  // put your main code here, to run repeatedly
  uint16_t numpulse=listenForIR(); // Wait for an IR Code

  // Process the pulses to get a single number representing code
  for (int i = 0; i < 34; i++) {
    irCode=irCode<<1;
    if((pulses[i][0] * RESOLUTION)>0&&(pulses[i][0] * RESOLUTION)<500) {
      irCode|=0; 
    } else {
      irCode|=1;
    }
  }

  Serial.print("Received IR code...");
  Serial.println(irCode, HEX);

  //Check received IR code for comm header
  uint32_t irCopy = irCode;
  uint32_t received_header = irCopy>>25;
  received_header = received_header << 1;
  
  if (irCode == IR_REMOTE_PLAY) {
    chasePersist(strip.numPixels(), turquoise);
    chase(purple);
  }
  else if (irCode == IR_REMOTE_SELECT) {
    chasePersist(strip.numPixels(), magenta);
    chase(purple);
  } else if (received_header == 0x86) {
    badge_id_you = (irCopy>>18)&0x7F;

    //Compare received code with your code
    Serial.println("Received IR comm signal, comparing.. ");
    uint32_t pixels_to_light = compareAnswers(sending, irCode);
    //Light up NeoPixels based on the number of matching questions
    comparisonLights(pixels_to_light, green);
    delay(30000);
    chase(blue);
  } else if (irCode != 0) {
    chasePersist(strip.numPixels(), yellowOrange);
    chase(purple);
  }
  memset(pulses, 0, sizeof(pulses));
}

void button_press() { 
  irsend.sendNEC(sending, 32);
}

static void chasePersist(int numPixels, uint32_t c) {
 for(int i=0;i<numPixels;i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, c); // Moderately bright green color.
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayVal); // Delay for a period of time (in milliseconds).
  } 
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-1, 0); // Erase pixel a few steps back
      strip.show();
      delay(delayVal);
  }
}

void enablePinInterupt(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  if(digitalRead(buttonPin)) {  button_press(); }
}

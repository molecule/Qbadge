//******* Button *********//

const int buttonPin = 8; // #6 on port D, #8 on port B
int buttonVal = LOW;


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
int brightness = 85;
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

int mode = 0; // 0: answer questions, 1: show all functions.

void setup() {
  //Set up on-board LED
  pinMode(13, OUTPUT);

  // Button setup
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
  functionPtrs[16] = newFunction;
  functionPtrs[99] = red_flash;
  
  // Bluetooth setup
  Serial.begin(9600);
  // This message will only print right when the code runs
  // to view it again, you can restart the board
  Serial.println("Qbadge Classic Shindig...");
  delay(100);
}

void loop() {
  if(mode == 0) {
    String readString = readFromBluetooth();
    displayBasedOnInput(readString);
  } else {
    int temp = questionsAnswered;
    for(int i = 1; i < NUM_QUESTIONS; i++) {
      if ((temp & QUESTION_MASK_MAP[i]) == QUESTION_MASK_MAP[i]) {
        callFunction(i);
        delay(DISPLAY_DELAY/3);
        callFunction(0);
        delay(30);
        if (mode == 0) {
          return;
        }
      }
    }
  }
}

void reportCorrectQuestions() {
  int temp = questionsAnswered;
  for(int i = 1; i < NUM_QUESTIONS; i++) {
    if((temp & QUESTION_MASK_MAP[i]) == QUESTION_MASK_MAP[i]) {
      strip.setPixelColor(i, blue);
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
  if(mode == 0) {
    mode = 1;
    digitalWrite(13, HIGH);
  } else {
    mode = 0;
    digitalWrite(13, LOW);
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

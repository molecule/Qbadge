//******** Neopixel *********** //
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIXEL_PIN 4
#define N_LEDS 18
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int delayVal = 50;

uint32_t magenta       = strip.Color(24, 0, 24);
uint32_t purple        = strip.Color(17, 0, 44);
uint32_t yellowOrange  = strip.Color(44, 30, 0);
uint32_t turquoise     = strip.Color(0, 50, 24);
uint32_t green         = strip.Color(0, 24, 0);
uint32_t red           = strip.Color(24, 0, 0);
uint32_t blue          = strip.Color(0, 0, 24);

boolean lightPixels = false;

void setup() {
  // Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  // To run a different function, change this method call to something else
  rainbowCycle();
  myNeopixelFunction(strip.numPixels(), turquoise);
  // This just turns off all the LEDs
  chase(blue);
}

static void myNeopixelFunction(int numPixels, uint32_t c) {
 for(int i=0;i<numPixels;i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, c);
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayVal); // Delay for a period of time (in milliseconds).
  } 
}

/*
 * Turn off all LEDs
 */
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-1, 0); // Erase pixel a few steps back
      strip.show();
      delay(delayVal);
  }
}

// An equally distributed rainbow. Is there any other kind?
void rainbowCycle() {
  uint8_t wait = 5;
  uint16_t i, j;

  for(j=0; j<256*2; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.setBrightness(75); strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

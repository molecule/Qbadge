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
  turquoise_flash();
  // This just turns off all the LEDs
  chase(blue);
}

void turquoise_flash() {
  cycle_color_flash(25, 51, 42);
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

void cycle_color_flash(int rStart, int gStart, int bStart) {
  int Rstart = rStart;
  int Gstart = gStart;
  int Bstart = bStart;


  // setting the "end" values to 0 means the LEDs will fade
  // too off. You can change these to other color values
  // to fade between two colors.
  int Rend, Gend, Bend = 0;
  int n = 100;
  for(int i = 0; i < n; i++) {// larger values of 'n' will give a smoother/slower transition.
    for(int j = 0; j<strip.numPixels(); j++) {
      float Rnew = Rstart + (Rend - Rstart) * i / n;
      float Gnew = Gstart + (Gend - Gstart) * i / n;
      float Bnew = Bstart + (Bend - Bstart) * i / n;
      strip.setPixelColor(j, strip.Color(Rnew, Gnew, Bnew));
    }
    strip.show();
    delay(10);
  }  
}

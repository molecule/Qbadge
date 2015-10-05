uint16_t listenForIR() {  // IR receive code
  currentpulse = 0;
  while (1) {
   unsigned int highpulse, lowpulse;  // temporary storage timing
   highpulse = lowpulse = 0; // start out with no pulse length 
  
   while (IRrx_PIN_VECTOR & _BV(IRrx)) { // got a high pulse
      highpulse++; 
      delayMicroseconds(RESOLUTION);
      if (((highpulse >= MAXPULSE) && (currentpulse != 0))|| currentpulse == NUMPULSES) {
        return currentpulse; 
      }
   }
   pulses[currentpulse][0] = highpulse;

   while (! (IRrx_PIN_VECTOR & _BV(IRrx))) { // got a low pulse
      lowpulse++; 
      delayMicroseconds(RESOLUTION);
      if (((lowpulse >= MAXPULSE) && (currentpulse != 0))|| currentpulse == NUMPULSES) {
        return currentpulse; 
      }
   }
   pulses[currentpulse][1] = lowpulse;
   currentpulse++;
  }
}


/**
 * Compares two 18-bit survey responses.
 */
uint32_t compareAnswers(uint32_t my_IR_code, uint32_t their_IR_code) {
  uint32_t mask = 0x3FFFF;
  uint32_t my_answers = my_IR_code & mask;
  Serial.print("My answers ");
  Serial.println(my_answers, BIN);
  uint32_t their_answers = their_IR_code & mask;
  Serial.print("Their answers ");
  Serial.println(their_answers, BIN);
  uint32_t result = (~(my_answers ^ their_answers));
  return result;
}

/**
 * Turns on the LEDs according to the answers.
 * If they answered the same, the pixels will light up to be the passed-in color.
 * Otherwise, the pixels will be hot_pink.
 */
static void comparisonLights(uint32_t pixels_to_light, uint32_t c) {
 uint32_t temp = pixels_to_light;
 for(int i=0;i<18;i++) {
      if ((temp & 0x0001) == 0x0001) {
        strip.setPixelColor(i, c);
      } else {
        strip.setPixelColor(i, hot_pink);
      }
      temp = temp>>1;
  }
  strip.show(); // This sends the updated pixel color to the hardware.
}

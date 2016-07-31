
/**
 * The loop that runs when we're in "Networking" mode.
 * 
 * Based on Trinket/Gemma compatible IR read sketch
 * This sketch/program uses an Adafruit Trinket or Gemma
 * ATTiny85 based mini microcontroller and a PNA4602 or TSOP38238 to
 * read an IR code and perform a function.  
 * Based on Adafruit tutorial http://learn.adafruit.com/ir-sensor/using-an-ir-sensor
 * and http://learn.adafruit.com/trinket-gemma-mini-theramin-music-maker
*/
void ir_loop() {
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

  //Serial.println(irCode, HEX);
  
  //Check received IR code for comm header
  uint32_t irCopy = irCode;
  uint32_t received_header = irCopy>>25;
  received_header = received_header << 1;
  
 if (irCode == IR_REMOTE_PLAY) {
    chasePersist(strip.numPixels(), turquoise);
    chase();
  }
  else if (irCode == IR_REMOTE_SELECT) {
    chasePersist(strip.numPixels(), hot_pink);
    chase();
  } else if (received_header == 0x86) {

    badge_id_you = (irCopy>>18)&0x7F;
    // Send ID over BLE
    char buffer[32];
    sprintf(buffer,"AT+QBEACON=%02X,%02X",badge_id_me, badge_id_you);
    Serial.println(buffer);

    //Compare received code with your code
    //Serial.println("Received IR comm signal, comparing.. ");
    uint32_t pixels_to_light = compareAnswers(sending, irCode);
    //Light up NeoPixels based on the number of matching questions
    comparisonLights(pixels_to_light, green);
    delay(30000);
    chase();
  } else if (irCode != 0) {
    chasePersist(strip.numPixels(), yellowOrange);
    chase();
  }
  memset(pulses, 0, sizeof(pulses));
  
}

 /** 
  *  From the Raw IR decoder sketch!
  *  This sketch/program uses the Arduno and a PNA4602 to
  *  decode IR received. This can be used to make a IR receiver
  *  (by looking for a particular code)
  *  or transmitter (by pulsing an IR LED at ~38KHz for the
  *  durations detected
  *  Code is public domain, check out www.ladyada.net and adafruit.com
  *  for more tutorials!
*/
uint16_t listenForIR() {  // IR receive code
  currentpulse = 0;
  while (mode) {
   unsigned int highpulse, lowpulse;  // temporary storage timing
   highpulse = lowpulse = 0; // start out with no pulse length 
  
   while (IRrx_PIN_VECTOR & _BV(IRrx)) { // got a high pulse
      highpulse++; 
      delayMicroseconds(RESOLUTION);
      if (((highpulse >= MAXPULSE) && (currentpulse != 0)) || currentpulse == NUMPULSES) {
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

/**
 * Compares two 18-bit survey responses.
 */
uint32_t compareAnswers(uint32_t my_IR_code, uint32_t their_IR_code) {
  uint32_t mask = 0x3FFFF;
  uint32_t my_answers = my_IR_code & mask;
  //Serial.print("My answers ");
  //Serial.println(my_answers, BIN);
  uint32_t their_answers = their_IR_code & mask;
  //Serial.print("Their answers ");
  //Serial.println(their_answers, BIN);
  uint32_t result = (~(my_answers ^ their_answers));
  return result;
}

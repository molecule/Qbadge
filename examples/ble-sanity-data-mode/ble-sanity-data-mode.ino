//******** Neopixel *********** //
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define NEOPIXEL_PIN 4
#define NUM_LEDS 18
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int delayVal = 50;

uint32_t leaf_green    = strip.Color(30, 44, 0);
uint32_t purple        = strip.Color(17, 0, 44);
uint32_t yellowOrange  = strip.Color(44, 30, 0);
uint32_t blue          = strip.Color(0, 0, 24);
uint32_t hot_pink      = strip.Color(48, 0, 24);

String AT_COMMAND_RX_SUCCESSFUL = String("OK");         // AT Command received successful
String AT_COMMAND_RX_FAILED = String("ERROR");          // AT Command received failed
String AT_COMMAND_MAC_RESPONSE = String("MAC");         // Response from “AT+MAC\n” command with xxxxxxxx = to 4btye hexadecimal BLE MAC address
String AT_CONNECTION_ESTABLISHED = String("CONNECTED"); // Response when connection is established in “AT+DATA\n” mode
String AT_CONNECTION_REMOVED = String("DISCONNECTED");  // Response when connection is torn down in “AT+DATA\n” mode

int mode = 0;

void setup() {
  //Set up on-board LED
  pinMode(13, OUTPUT);

  // Bluetooth setup
  Serial.begin(9600);
  while(!Serial) {;}
  Serial.println("AT+DATA");
  
  // Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

String response;
char readString[32];
 
void loop() {  
  
  response = readFromBluetooth();
  displayBasedOnInput(response);
 
}

void displayBasedOnInput(String response) {
   if(response.length()>1)
  {
  
    if(response==AT_COMMAND_RX_SUCCESSFUL) {
      chasePersist(strip.numPixels(), leaf_green);
      chase();
    }
    else if (response == String("CDMA")) {
      chasePersist(strip.numPixels(), yellowOrange);
      chase();
    }
    else if (response == String("QCOM")) {
      chasePersist(strip.numPixels(), hot_pink);
      chase();
    }
    else {
      chase();
    }
  }
}


String readFromBluetooth1() {
  char c = 0;
  int windex=0;
  readString[0]=0;
  
  while( ((c != '\n') && (c!='\r')) )
  { 
    while (Serial.available()>0) 
    {
      c = Serial.read();  //gets one byte from serial buffer

      if ( ((c != '\n') && (c!='\r')) )
      { 
        readString[windex]=c;
        readString[windex+1]=0;
        windex++;
      }
      else
      {
        break;
      }
    }
  } 
  return String(readString);
}

String readFromBluetooth() {
  String readString = "";
  
    while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    //char c = bluetoothSerial.read();  //gets one byte from serial buffer
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      break;
    }
    readString += c;
  } 
  return readString;
}

static void chasePersist(int numPixels, uint32_t c) {
 for(int i=0;i<numPixels;i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, c); // Moderately bright green color.
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(delayVal); // Delay for a period of time (in milliseconds).
  } 
}

static void chase() {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , blue); // Draw new pixel
      strip.setPixelColor(i-1, 0); // Erase pixel a few steps back
      strip.show();
      delay(delayVal);
  }
}

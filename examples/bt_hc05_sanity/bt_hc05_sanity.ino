// SERIAL LOOP SKETCH FOR COMMUNICATING WITH A BLUETOOTH SPP MODULE

// BASE HC-05 Config Commands

// Full list of codes: https://developer.mbed.org/users/edodm85/notebook/HC-05-bluetooth/
// AT+ORGL （Restore the factory default state）
// AT+UART=115200,0,0 （Set transmission rate to 115200 bps, one stop bit and no parity bit）
// AT+NAME=Smoothie
// AT+PSWD=0000 Set pairing code to 0000

// Make sure the BT of Mac is turned on.
// opened BT preferences on Mac and get connected. 
// Default pairing code was 1234

// More documentation: http://www.instructables.com/id/AT-command-mode-of-HC-05-Bluetooth-module/?ALLSTEPS
// Module we purchased: http://www.amazon.com/gp/product/B00L083QAC?psc=1&redirect=true&ref_=oh_aui_detailpage_o00_s00&tag=s4charity-20

#include <SoftwareSerial.h>

#define pinRX 0
#define pinTX 1
SoftwareSerial mySerial(pinRX, pinTX); // RX, TX
char val;

void setup() {
  pinMode(pinRX, INPUT);
  pinMode(pinTX , OUTPUT);  
  mySerial.begin(9600);    
  delay(100);
}
void loop() {  
  mySerial.println("Bluetooth 31");
  delay(1000);
}

#Qbadge Classic

##General Info
The PIN for the badges is "1234"

The main difference between Qbadge Classics and Qbadge v2s is the bluetooth module. 

Qbadge Classic: HC-05 Bluetooth 2.0 module

Qbadge v2: BLE Nano Bluetooth 4.0 module

If you'd like to connect to the badges using an Android app, you can try any called "Bluetooth Terminal" or similar. 
I've tried about four different apps and they all seem to work.

Instructions for how to install the Adafruit Neopixel libraries: 

https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library

More info on the exact HC-05 modules inside:

http://www.instructables.com/id/Arduino-AND-Bluetooth-HC-05-Connecting-easily/

http://www.amazon.com/JBtek-Wireless-Bluetooth-Transceiver-Arduino/dp/B00L083QAC?tag=s4charity-20


##Video Walkthroughs
Uploading code. NOTE: I don't mention it in the video, but please be sure to unplug the grey wire and 
the white wire from the Pro Trinket before uploading. The USB bootloader on the Pro Trinket
can be a little finicky, and if it gets any weird input on RX or TX while it's trying to upload, you
could see some strange issues: 

https://www.youtube.com/watch?v=1vI0XHwC2lc

Connecting to BT 2.0 from a Mac: 

https://www.youtube.com/watch?v=gR_pwT6IPN8

##Troubleshooting
Lots of USB errors? Timeouts, etc?
Try adding a pull-up resistor between RX and the 3.3V output

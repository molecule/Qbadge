#Qbadge Classic

##General Info
The pin for the badges is "1234"

If you'd like to connect to the badges using an Android app, you can try any called "Bluetooth Terminal". 
I've tried about four differnet apps and they all seem to work pretty well.

Instructions for how to install the Adafruit Neopixel libraries: 

https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library

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

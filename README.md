#Qbadge

##Enjoy your Qbadge!

This little wearable is so much more than it first appears… At this exclusive event you’ll discover just how much you can do with hardware. Especially when it’s combined with the power of a community board like Qualcomm’s 410c Dragonboard. The Internet of Things awaits… 

##Guided tour

Aside from the beautiful LEDs, the Qbadge also has lots of ways to communicate. The front of the Qbadge has an infrared receiver, an intrared transmitter, a button to trigger an action, and a microphone. 

<img style="float: center;" src="http://i.imgur.com/TSINq4r.png">

On the inside, there’s also a BLE module tucked away beneath the main processor board.

<img style="float: center;" src="http://i.imgur.com/JZkmjEx.png">

## Set up your computer to work with the Gemma boards
### 1. The first step is to download and install the drivers.

a. Go to [download the drivers from Adafruit](https://learn.adafruit.com/adafruit-arduino-ide-setup/windows-setup).

OR

a. Go to [codebender.cc](Codebender.cc). Register a new account. Create a new profile and just go through each of the steps. It will download and install the drivers.

c. When it asks you for the board, select the Adafruit Gemma 8MHz made by Adafruit. It will 
automatically select the correct programmer, which is USBTinyISP. NOTE: You can stop after the drivers
have installed, OR you can go all the way to the end of the "Getting Started" sequence, and load 
“blink” onto your Gemma as a test. Don't forget to put your Gemma into "Bootloader" mode by pressing
the "reset" button on the board.

<img style="float: center;" src="http://i.imgur.com/S5buZln.png">

### 2. Follow these instructions to download and install the Integrated Development Environment (IDE). 

An "IDE" is basically a fancy text editor that you will use to make changes to the code. Similar to how Microsoft Word is a place to type letters, essays, etc, in your IDE you'll type code!

a. First you'll download and install the Arduino IDE from this link. You may need to select "YES" if it asks you to make changes to the computer.:
[Arduino IDE download](https://www.arduino.cc/en/Main/Software)

b. Once you've installed the IDE, continue with the instructions under "Super Easy Installation" at the next link. The last step you need to do on this list is adding the "Contributed boards" in the "Board Manager." 

https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide

c. NOTE: You don't need to download the drivers, or do the "Easy Installation." 
Once you've added the "Contributed boards" you are finished with this step.

### 3. You also need to install the Adafruit Neopixel library. Follow instructions here:
https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation

To load code onto your Qbadge, you can use a site called "CodeBender":

https://codebender.cc/

Follow these instructions to install the IDE to work with the Pro Trinket inside your Qbadge:

https://learn.adafruit.com/introducing-pro-trinket/starting-the-bootloader

You'll also need the Adafruit Neopixel library: 

https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library

And the IR Remote library (be sure to download V1.0):

https://github.com/z3t0/Arduino-IRremote/releases

### Working with the BLE Nano
#### Upload the custom bootloader to the Nano
1. Connect the BLE device (VDD, GND, DIO, DCLK):
2. Load firmware:
3. Test device:

#### Upload firmware to the Nano
1. Download nRF Toolbox:
2. Click on "DFU"
3. Click on "Select file"
4. Select Distribution Package (ZIP) and then click "OK"
5. Click on Dropbox
6. Select the file (latest ble_qbadge_x.zip file)
7. Click on "Select device"
8. Device name should be DFUTARG
9. Click "Upload"
10. Wait until it is finished successfully.

###Helpful Guides

Info for installing Arduino libraries:

https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/arduino-libraries

Info about the Pro Trinket 3V inside the Qbadge:

https://learn.adafruit.com/introducing-pro-trinket/overview

Info about the BLE Nano inside the Qbadge:

http://redbearlab.com/blenano/


##Helpful videos
How to open, close, and power on your Qbadge:
https://www.youtube.com/watch?v=6eYyS4wtiWs

Networking mode demo:
https://www.youtube.com/watch?v=jLXpunxlupk

Question Quest mode demo:
https://www.youtube.com/watch?v=DJcJaX-GzcY

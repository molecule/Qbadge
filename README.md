#Qbadge

##Helpful videos
[How to open, close, and power on your Qbadge](https://www.youtube.com/watch?v=6eYyS4wtiWs)

[Networking mode demo](https://www.youtube.com/watch?v=jLXpunxlupk)

[Question Quest mode demo](https://www.youtube.com/watch?v=DJcJaX-GzcY)

[Switching modes](https://www.youtube.com/watch?v=-lT2BPnJW98)


## Set up your computer to work with the Pro Trinket boards
### 1. Download and install the drivers (only needed for Window computers, not Macs).

a. Go to [download the drivers from Adafruit](https://learn.adafruit.com/adafruit-arduino-ide-setup/windows-setup).

OR

a. Go to [codebender.cc](Codebender.cc). Register a new account. Create a new profile and just go through each of the steps. It will download and install the drivers.

c. When it asks you for the board, select the Adafruit Pro Trinket 3.3v 12MHz made by Adafruit. It will 
automatically select the correct programmer, which is USBTinyISP. NOTE: You can stop after the drivers
have installed, OR you can go all the way to the end of the "Getting Started" sequence, and load 
“blink” onto your Pro Trinket as a test. Don't forget to put your Pro Trinket into "Bootloader" mode by pressing
the "reset" button on the board.

<img style="float: center;" src="http://i.imgur.com/S5buZln.png">

### Download and install the Integrated Development Environment (IDE). 

An "IDE" is basically a fancy text editor that you will use to make changes to the code. Similar to how Microsoft Word is a place to type letters, essays, etc, in your IDE you'll type code!

a. First you'll download and install the Arduino IDE from this link. You may need to select "YES" if it asks you to make changes to the computer.:
[Arduino IDE download](https://www.arduino.cc/en/Main/Software)

b. Once you've installed the IDE, continue with the instructions under "Super Easy Installation" at the next link. The last step you need to do on this list is adding the "Contributed boards" in the "Board Manager." 

https://learn.adafruit.com/adafruit-arduino-ide-setup/arduino-1-dot-6-x-ide

c. NOTE: You don't need to download the drivers, or do the "Easy Installation." 
Once you've added the "Contributed boards" you are finished with this step.

### Install libraries.
You also need to install a few different libraries. To learn how to add libraries, check out Adafruit's instructions here:

https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use

You'll need the Adafruit Neopixel library: 

https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation

And the IR Remote library (be sure to download V1.0):

https://github.com/z3t0/Arduino-IRremote/releases

### Uploading code to the Qbadge
1. Setup the IDE. The board should be "Adafruit Pro Trinket 3.3v 12MHz" made by Adafruit. The programmer is USBTinyISP.
(Video available soon...)

### Working with the BLE Nano
#### Upload the custom bootloader to the Nano
1. Disconnect all the wires from the Qbadge:
  <img style="float: center;" src="http://i.imgur.com/sdXwdAV.jpg?1">
2. Get 4 male-female jumper wires. Plug in the male end of the wires to the BLE-USB dongle:

  ```
  Orange wire --> VDD
  Blue wire --> GND
  Yellow wire --> DIO
  Green wire --> DCLK
  
  ```

  <img style="float: center;" src="http://i.imgur.com/7FwELPN.jpg?1">
  <img style="float: center;" src="http://i.imgur.com/gLyCw95.jpg?1">
3. While the USB dongle is disconnected from the computer, connect the BLE device by connecting the female end of the wires to the Qbadge as shown:
  <img style="float: center;" src="http://i.imgur.com/0LCUHoq.jpg?1">
  <img style="float: center;" src="http://i.imgur.com/d2T8pdt.jpg?1">
  <img style="float: center;" src="http://i.imgur.com/GHzqiw5.jpg?1">
4. Connect the USB dongle to the computer:
  <img style="float: center;" src="http://i.imgur.com/OpSUDMB.jpg?1">
5. Load the bootloader by dragging the latest copy of the bootloader (ble_dfu_4.hex) to the "MBED" device connected to the computer. Note that it will disconnet itself from the computer, and the computer may complain about not safely ejecting the device, but it's expected behavior:
  <img style="float: center;" src="http://i.imgur.com/Z6qEdkG.jpg?1">

#### Upload firmware to the Nano (instructions for Android)
1. Download nRF Toolbox:

  <img style="float: center;" src="http://i.imgur.com/KzxPDtX.jpg?1">
2. Click on "DFU"
3. Click on "Select file"
4. Select Distribution Package (ZIP) and then click "OK"
5. Click on Dropbox
6. Select the file (latest ble_qbadge_x.zip file)
7. Click on "Select device"
8. Device name should be DFUTARG
9. Click "Upload"
10. Wait until it is finished successfully.
11. The Arduino code will update the advertising name of the Qbadge as soon as it's turned on.

###Helpful Guides

Info for installing Arduino libraries:

https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/arduino-libraries

Info about the Pro Trinket 3V inside the Qbadge:

https://learn.adafruit.com/introducing-pro-trinket/overview

Info about the BLE Nano inside the Qbadge:

http://redbearlab.com/blenano/




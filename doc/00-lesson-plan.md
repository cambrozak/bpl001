#Session Zero: Development Environment Setup

It is recommended that setup is completed by the instructor
on all lab machines before the first day of class so that problems
with hardware and software are identified and fixed without cutting into
valuable student class time.

Environment setup is an important learning moment for experienced and novice
programmers alike.  However, This course defers on this topic to the
session that focuses on debugging and troubleshooting in order to get
students loading programs on the robot right away.

##Verify USB Ports
Lab machines must provide at least one Standard USB 2.0 port, two is ideal.

USB 3.0 and 'high power' ports will power the Zumo, but will not upload code.

##Use a Consistent User Profile
The 'Patron' User Profile will be used by students, be sure to perform these setup steps as the Patron user.

##Install IDE
Arduino IDE Download and instructions<br>
https://www.arduino.cc/en/Main/Software

##Install A-Star Drivers
Zumo 32U4 requires specific drivers for Windows<br>
https://www.pololu.com/docs/0J63/all#5

Be sure to extract all files from the zip archive on Windows 7 before attempting to right-click/install.

##Install Zumo Libraries and Load the Test Blink Program
Be mindful of the first-time issues noted in this step.<br><br>
https://www.pololu.com/docs/0J63/all#5.2

##Update Zumo Libraries
The Zumo examples will appear in the Examples menu once this step is complete.

1. Run the Arduino IDE
2. Open the Library Mangeger from the main menu: Sketch > Include Library... > Manage Libraries
3. Search for 'zumo'
4. Click the Zumo32U4 Arduino Library, an 'Install' button appears, click it.
5. Click the 'Close' button on the bottom right corner.

Confirm that the libraries are loaded by opening the Examples from the main menu: File > Examples > Zumo32U4

##Load a Zumo Test Example
File > Examples > Zumo 32U4 > BuzzerBasics

##Reminder for Students
Students should now be able to load programs without issue.  They may need to manually set the target Board and Port occassionally.

Write this reminder on the board at the beginning of each session:

**Login as 'Patron' user**

**Plug Robot into USB 2.0 Port (rear left on the laptop)**

**Tools > Board > Pololu A-Star 32U4**

**Tools > Port > COMX**

## Fixing Port Dropoff

The IDE can fail to detect the port connection under certain conditions.  The fix for this is to use the Reset button to put the Zumo in bootloader mode during upload.  The IDE will detect the port in bootloader mode.  Follow these steps exactly:

1. Connect the device to your computer via USB.
2. In the “Tools” menu, open the “Board” sub-menu, and select “Pololu A-Star 32U4”.
3. In the “Tools” menu, open the “Port” sub-menu, and check to see if any ports are selected. If the “Port” menu is grayed out or no ports in it are selected, that is good, and you can skip to step 6.
4. Press the Reset button twice to get the board into bootloader mode.  While the board is in bootloader mode, quickly select the new serial port that corresponds to the bootloader in the “Port” menu in the IDE.
5. After 8 seconds, the bootloader will exit and attempt to run the sketch again. Wait for the bootloader to exit. Verify that either the “Port” menu is grayed out or no ports in it are selected.
6. Click the Upload button. The Arduino IDE will compile your sketch and start uploading it.
7. As soon as the large status bar near the bottom of the IDE says “Uploading…”, press reset the board twice to get into bootloader mode.

The Arduino IDE will stay in the uploading phase for 10 seconds, waiting for a new serial port to appear. Once the serial port of the bootloader appears, the Arduino IDE will connect to it and send programming commands.

More details are [here](https://www.pololu.com/docs/0J63/9.1)

##Pixy Setup

**Install PixyMon vision system monitor client**
[http://www.cmucam.org/projects/cmucam5/wiki/Installing_PixyMon_on_Windows_Vista_7_or_8](http://www.cmucam.org/projects/cmucam5/wiki/Installing_PixyMon_on_Windows_Vista_7_or_8)

**Install Pixy Arduino Library**<br>
[http://www.cmucam.org/projects/cmucam5/wiki/Latest_release](http://www.cmucam.org/projects/cmucam5/wiki/Latest_release)<br>

**Set I2C Interface**<br>
Select I2C in the Interface section of Preferences<br>


<sup><sub>*BPL001 Introduction to Robotics by Carlos Ambrozak* is licensed under a Creative Commons Attribution 4.0 International License.</sub></sup>

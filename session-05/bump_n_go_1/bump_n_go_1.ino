// Bump-n-Go by Carlos Ambrozak

// Start by collecting and displayig Accelerometer G-Force values
// x is the force forward and backward
// y is the force left and right
// z is the force up and down towards the center of the earth
// 1g will register as about 16384 on the z axis according to the LSM303 documentation
// https://github.com/pololu/lsm303-arduino#library-reference
//
// Observe how z stays constant but x and y vary rapidly when the robot is not even moving.

// LIBRARIES

// Zumo32U4.h is the main library for interfacing with the following Zumo hardware:
// Button A, LSM303 Acceleromter chip, LCD screen
#include <Zumo32U4.h>

// Wire.h controls communication over the I2C data bus
// bewteen LSM303 chip and the main ATmega32U4 Microcontroller chip
#include <Wire.h>

// OBJECTS
// This section sets up instance variables for the main Zumo hardware objects
Zumo32U4ButtonA buttonA; 
LSM303 lsm303;
Zumo32U4LCD lcd;

// FUNCTION DECLARATIONS
void waitForButtonA();
void collectSamples();
void displayData();

// GLOBAL VARIABLES

// SETUP
void setup() {
  
  // Don't do anything until Button A is pushed
  waitForButtonA();

  // Start up the I2C bus communication
  Wire.begin();

  // Initialize LSM303 bus communication
  lsm303.init();

  // Turn on Accelerometer
  lsm303.enableDefault();
}

// MAIN LOOP
void loop() {
  
  // collect samples and display input at about 16MHz
  collectSamples();
  displayData();
}

// FUNCTION IMPLEMENTATIONS

// This function reads values from the Acceleromter
// The values are stored in lsm303.a.x, lsm303.a.y, lsm303.a.z
void collectSamples() {
    lsm303.readAcc();
}

// This function displays Accelerometer values x, y and z on the LCD
void displayData() {
  
  // clear the screen
  lcd.clear();

  // print x and y on the top line
  lcd.print(lsm303.a.x);
  lcd.print(lsm303.a.y);

  // print z on the bottom line
  lcd.gotoXY(0, 1);
  lcd.print(lsm303.a.z);

  // delay 25 milliseconds to make LCD readable
  delay(25);
}

// This function prints a prompt on the LCD screen 
// and pauses execution until Button A is pressed
void waitForButtonA() {
  
  // clear the screen
  lcd.clear();

  // print the prompt on the top line
  lcd.print("Press A");

  // pause execution until Button A is pressed
  buttonA.waitForButton();

  // delay 1 second to allow time for pulling fingers away from the robot
  delay(1000);
}


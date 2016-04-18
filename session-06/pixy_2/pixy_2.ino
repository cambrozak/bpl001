// Center the Servo Arm

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// VARIABLES
uint16_t panPosition;
uint16_t tiltPosition;

// OBJECTS
Zumo32U4ButtonC buttonC;
Zumo32U4LCD lcd;
PixyI2C pixy(0x54);

// FUNCTION DECLARATIONS
void displayServoPositions();
void blinkPixyLED();

// SETUP
void setup() {
  pixy.init();
}

// MAIN LOOP
void loop() {
  //center
  panPosition = PIXY_RCS_CENTER_POS;
  tiltPosition = PIXY_RCS_CENTER_POS;
  pixy.setServos(panPosition, tiltPosition);
  displayServoPositions();
  delay(1000);

  // pan left
  panPosition = PIXY_RCS_MAX_POS;
  pixy.setServos(panPosition, tiltPosition);
  displayServoPositions();
  delay(1000);

  // pan right
  panPosition = PIXY_RCS_MIN_POS;
  pixy.setServos(panPosition, tiltPosition);
  displayServoPositions();
  delay(1000);
  
  blinkPixyLED();

  buttonC.waitForButton();
  delay(500);
}

// FUNCTION IMPLEMENTATIONS

// Display servo pan tilt positions on LCD
void displayServoPositions() {
  lcd.clear();
  lcd.print("PAN ");
  lcd.print(panPosition);
  lcd.gotoXY(0, 1);
  lcd.print("TLT ");
  lcd.print(tiltPosition);
  delay(25);
}

// Blink Pixy LED once per second
void blinkPixyLED() {
  pixy.setLED(0, 255, 0);
  delay(1000);
  pixy.setLED(0, 0, 0);
  delay(1000);
}


// Fold the servo arm for storage and blink once to confirm

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// VARIABLES
uint16_t panPosition;
uint16_t tiltPosition;

// OBJECTS
Zumo32U4ButtonC buttonC;
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
  delay(1000);

  // fold back
  tiltPosition = PIXY_RCS_MIN_POS;
  pixy.setServos(panPosition, tiltPosition);
  delay(1000);
  
  blinkPixyLED();

  buttonC.waitForButton();
  delay(500);
}

// FUNCTION IMPLEMENTATIONS
void blinkPixyLED() {
  pixy.setLED(0, 255, 0);
  delay(1000);
  pixy.setLED(0, 0, 0);
  delay(1000);
}


// Move the servos with buttons
// Button A: Pan Left
// Button B: Tilt Up
// Button C: Pan Right

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// VARIABLES
#define DELAY 250
#define DELTA 50

uint16_t panPosition;
uint16_t tiltPosition;

// OBJECTS
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Buzzer buzzer;

PixyI2C pixy(0x54);

// FUNCTION DECLARATIONS
uint16_t calculateServoPosition(uint16_t position, uint16_t delta);
void setLights();
void centerServoPositions();
void displayServoPositions();
void blinkPixyLED();

// SETUP
void setup() {
  pixy.init();
  centerServoPositions();
  displayServoPositions();
}

// MAIN LOOP
void loop() {

  if (buttonA.getSingleDebouncedPress()) {
    panPosition = calculateServoPosition(panPosition, DELTA);
    pixy.setServos(panPosition, tiltPosition);
    setLights(1, 0, 0);
    displayServoPositions();
    blinkPixyLED();
  }
  
  if (buttonB.getSingleDebouncedPress()) {
    tiltPosition = calculateServoPosition(tiltPosition, -DELTA);
    pixy.setServos(panPosition, tiltPosition);
    setLights(0, 1, 0);
    displayServoPositions();
    blinkPixyLED();
  }

  if (buttonC.getSingleDebouncedPress()) {
    panPosition = calculateServoPosition(panPosition, -DELTA);
    pixy.setServos(panPosition, tiltPosition);
    displayServoPositions();
    setLights(0, 0, 1);
    blinkPixyLED();
  }
}

// FUNCTION IMPLEMENTATIONS

// Adjust position by delta, not exeeding max allowable values
uint16_t calculateServoPosition(uint16_t position, uint16_t delta) {
  uint16_t p = position + delta;

  if (p >= PIXY_RCS_MAX_POS) {
    p = PIXY_RCS_MAX_POS;
    buzzer.playNote(NOTE_A(4), 200, 10);    
  } else if (p <= PIXY_RCS_MIN_POS) {
    p = PIXY_RCS_MIN_POS;
    buzzer.playNote(NOTE_G(4), 200, 10);
  } else if (p == PIXY_RCS_CENTER_POS) {
    buzzer.playNote(NOTE_D(4), 200, 10);
  }
  
  return p;
}

// Set lights to indicate last button push
// Button A: Yellow LED
// Button B: Green LED
// Button C: Red LED
void setLights(int yellow, int green, int red) {
  ledYellow(yellow);
  ledGreen(green);
  ledRed(red);
  return;
}

// Set pan and tilt servo positions to midpoint
void centerServoPositions() {
  panPosition = PIXY_RCS_CENTER_POS;
  tiltPosition = PIXY_RCS_CENTER_POS;
  pixy.setServos(panPosition, tiltPosition);
}

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
  delay(DELAY);
  pixy.setLED(0, 0, 0);
  delay(DELAY);
}



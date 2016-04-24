// Scan, Track and Follow by Carlos Ambrozak
// Based on the PixyPet example at Adafruit
// https://learn.adafruit.com/pixy-pet-robot-color-vision-follower-using-pixycam/the-code

// LIBRARIES
#include <Zumo32U4.h>
#include <Pixy.h>
#include "Feedback.h"

// VARIABLES
#define MAX_SPEED 200
#define MAX_REVERSE_SPEED 170
#define SCAN_SPEED 150

const uint32_t DISPLAY_TIME = 25;
const uint32_t SCAN_TIME = 20;
const uint32_t SCAN_DELAY_MIN = 150;
const uint32_t SCAN_DELAY_MAX = 300;
const uint32_t SCAN_DISTANCE_FACTOR = 125;
const float TILT_DISTANCE_FACTOR = 0.6;

uint32_t PIXY_X_CENTER = ((PIXY_MAX_X - PIXY_MIN_X) / 2);
uint32_t PIXY_Y_CENTER ((PIXY_MAX_Y - PIXY_MIN_Y) / 2);

uint32_t lastBlockTime = 0;
int lastX, lastY, lastSignature;
int32_t size = 400;
int scanIncrement = (PIXY_RCS_MAX_POS - PIXY_RCS_MIN_POS) / 150;
uint32_t lastScanTime = 0;
unsigned long lastDisplayTime = 0;

// OBJECTS
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4ButtonC buttonC;
Zumo32U4Buzzer buzzer;
PixyI2C pixy(0x54);
Feedback panFeedback(200, 200);
Feedback tiltFeedback(150, 200);

// FUNCTION DECLARATIONS
void scan();
int getLargestBlock(int blockCount);
void trackBlock(int block);
void displayBlock(int block);
void displayFeedback();


// SETUP
void setup() {
  pixy.init();
  lcd.clear();
  lcd.print("PRESS C");
  buttonC.waitForButton();
  lcd.clear();
}

// MAIN LOOP
void loop() { 
  uint16_t blocks = pixy.getBlocks();

  if (blocks) {
    int largestBlock = getLargestBlock(blocks);
    trackBlock(largestBlock);
    displayBlock(largestBlock);
    followBlock(largestBlock);
    lastBlockTime = millis();
  } else if ((millis() - lastBlockTime) > 100) {
    scan();
  }
}

// FUNCTION IMPLEMENTATIONS
void followBlock(int block) {
  int32_t followError = PIXY_RCS_CENTER_POS - panFeedback.mNextPosition; 

  // size is the area of the object.
  // keep a running average of the last 8.
  size += pixy.blocks[block].width * pixy.blocks[block].height; 
  size -= size >> 3;

  // forward speed decreases as the object gets closer (size is larger)
  int forwardSpeed = constrain(MAX_SPEED - (size / 256), -MAX_REVERSE_SPEED, MAX_SPEED);  

  // steering differential is proportional to the error times the forward speed
  int32_t differential = (followError + (followError * forwardSpeed)) >> 8;

  // adjust the left and right speeds by the steering differential
  int leftSpeed = constrain((forwardSpeed + differential), -MAX_SPEED, MAX_SPEED);
  int rightSpeed = constrain((forwardSpeed - differential), -MAX_SPEED, MAX_SPEED);

  motors.setSpeeds(leftSpeed, rightSpeed);
}

int getLargestBlock(int blockCount) {
  int largestBlock = 0;
  long maxSize = 0;

  for (int i = 0; i < blockCount; i++) {

    if ((lastSignature == 0) || (pixy.blocks[i].signature == lastSignature)) {

      long newSize = pixy.blocks[i].height * pixy.blocks[i].width;

      if (newSize > maxSize) {
        largestBlock = i;
        maxSize = newSize;
      }
    }
  }
  return largestBlock;
}

void trackBlock(int block) {
  int32_t panError = PIXY_X_CENTER - pixy.blocks[block].x;
  int32_t tiltError = pixy.blocks[block].y - PIXY_Y_CENTER;

  panFeedback.calculateNextPosition(panError);
  tiltFeedback.calculateNextPosition(tiltError);
    
  pixy.setServos(panFeedback.mNextPosition, tiltFeedback.mNextPosition);
  
  lastX = pixy.blocks[block].x;
  lastY = pixy.blocks[block].y;
  lastSignature = pixy.blocks[block].signature;
}

// Pan back and forth at random until a block is detected
void scan() {
  if (millis() - lastScanTime > SCAN_TIME) {
    lastScanTime = millis();

    panFeedback.mNextPosition += scanIncrement;

    if ((panFeedback.mNextPosition >= PIXY_RCS_MAX_POS) || (panFeedback.mNextPosition <= PIXY_RCS_MIN_POS)) {

      tiltFeedback.mNextPosition = random((PIXY_RCS_MAX_POS * TILT_DISTANCE_FACTOR), PIXY_RCS_MAX_POS);

      scanIncrement = -scanIncrement;


      if (scanIncrement < 0) {
        motors.setSpeeds(-SCAN_SPEED, SCAN_SPEED);
      } else {
        motors.setSpeeds(+180, -180);
      }

      delay(random(SCAN_DELAY_MIN, SCAN_DELAY_MAX));
    }

    pixy.setServos(panFeedback.mNextPosition, tiltFeedback.mNextPosition);
  }
}

void displayBlock(int blockIndex) {
  if ((millis() - lastDisplayTime) > DISPLAY_TIME) {
    lcd.clear();
    lcd.print("TRACKING");
    lcd.gotoXY(0, 1);
    lcd.print(pixy.blocks[blockIndex].signature);
    lastDisplayTime = millis();
  }
}

void displayFeedback() {
  lcd.clear();
  lcd.print(panFeedback.mPreviousError);
  lcd.print(" ");
  lcd.print(tiltFeedback.mPreviousError);
  lcd.gotoXY(0, 1);
  lcd.print(panFeedback.mVelocity);
  lcd.print(" ");
  lcd.print(tiltFeedback.mVelocity);
  buttonC.waitForButton();
}


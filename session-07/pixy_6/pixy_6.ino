// Determine the largest block in the field of vision

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// VARIABLES
#define DISPLAY_TIME 20
#define SCAN_TIME 20
#define SCAN_DELAY_MIN 150
#define SCAN_DELAY_MAX 300
#define SCAN_DISTANCE_FACTOR 125
#define TILT_DISTANCE_FACTOR 0.6

#define DELAY 250
#define DELTA 50

int scanDistance = (PIXY_RCS_MAX_POS - PIXY_RCS_MIN_POS) / SCAN_DISTANCE_FACTOR;
unsigned long lastScanTime = 0;
unsigned long lastDisplayTime = 0;
uint16_t panPosition;
uint16_t tiltPosition;

int lastSignature;

// OBJECTS
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;
PixyI2C pixy(0x54);

// FUNCTION DECLARATIONS
void scan();
void displayBlocks();
void displayServoPositions();


// SETUP
void setup() {
  pixy.init();
}

// MAIN LOOP
void loop() {
  
  uint16_t blocks = pixy.getBlocks();
  
  if (blocks) {
    int largestBlock = getLargestBlock(blocks);
    displayBlocks(largestBlock, blocks);
  } else {
    scan();
  }
}

// FUNCTION IMPLEMENTATIONS
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

void displayBlocks(int largestBlockIndex, int blockCount) {
  if ((millis() - lastDisplayTime) > DISPLAY_TIME) {
    lcd.clear();
    lcd.print("BLOCKS!!");
    lcd.gotoXY(0, 1);

    lcd.print(pixy.blocks[largestBlockIndex].signature);
    lcd.print(" ");
    
    for (int i = 0; i < blockCount; i++) {    
      lcd.print(pixy.blocks[i].signature);
      lcd.print(" ");  
    }
      
    lastDisplayTime = millis();
  }
}

// Pan left to right and tilt at random angles, like Terminator!
void scan() {
  if ((millis() - lastScanTime) > SCAN_TIME) {
    lastScanTime = millis();
    
    panPosition += scanDistance;
    
    if ((panPosition >= PIXY_RCS_MAX_POS) || (panPosition <= PIXY_RCS_MIN_POS)) {
      tiltPosition = random((PIXY_RCS_MAX_POS * TILT_DISTANCE_FACTOR), PIXY_RCS_MAX_POS);
      scanDistance = -scanDistance;
      delay(random(SCAN_DELAY_MIN, SCAN_DELAY_MAX));
    }
    
    pixy.setServos(panPosition, tiltPosition);
  }
}

// Display servo pan tilt positions on LCD
void displayServoPositions() {
  if ((millis() - lastDisplayTime) > DISPLAY_TIME) {
    lcd.clear();
    lcd.print("PAN ");
    lcd.print(panPosition);
    lcd.gotoXY(0, 1);
    lcd.print("TLT ");
    lcd.print(tiltPosition);
    lastDisplayTime = millis();
  }
}



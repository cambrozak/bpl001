// Scan: Pan left to right and tilt at random angles

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// VARIABLES
#define BLINK_TIME 500
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
unsigned long lastBlinkTime = 0;
unsigned long lastDisplayTime = 0;
int onOff = 255;
uint16_t panPosition;
uint16_t tiltPosition;

// OBJECTS
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;
PixyI2C pixy(0x54);

// FUNCTION DECLARATIONS
void scan();
void displayBlocks();
void displayServoPositions();
void blinkPixyLED();

// SETUP
void setup() {
  pixy.init();
}

// MAIN LOOP
void loop() {
  uint16_t blocks = pixy.getBlocks();
  if (blocks) {
    displayBlocks(blocks);
  } else {
    scan();
  }
}

// FUNCTION IMPLEMENTATIONS
void displayBlocks(int blockCount) {
  if ((millis() - lastDisplayTime) > DISPLAY_TIME) {
    lcd.clear();
    lcd.print("BLOCKS!!");
    lcd.gotoXY(0, 1);
    
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
  blinkPixyLED();
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

// Blink Pixy LED once per second
void blinkPixyLED() {
  if ((millis() - lastBlinkTime) > BLINK_TIME) {
    onOff = (onOff == 255) ? 0 : 255; 
    pixy.setLED(0, 0, onOff);
    lastBlinkTime = millis();
  }
}



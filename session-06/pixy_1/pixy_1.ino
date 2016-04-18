// Blink the Pixy LED to test I2C connection

// LIBRARIES
#include <Zumo32U4.h>
#include <PixyI2C.h>

// OBJECTS
PixyI2C pixy(0x54);
Zumo32U4LCD lcd;

// FUNCTION DECLARATIONS
void blinkPixyLED();

// GLOBAL VARIABLES

// SETUP
void setup() {
  pixy.init();
}

// MAIN LOOP
void loop() {
  blinkPixyLED();
}

// FUNCTION IMPLEMENTATIONS

// Blink Pixy LED once per second
void blinkPixyLED() {
  pixy.setLED(0, 255, 0);
  delay(1000);
  pixy.setLED(0, 0, 0);
  delay(1000);
}


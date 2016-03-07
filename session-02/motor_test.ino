/***
  Test motor acceleration and deceleration.
  Move forward and reverse.
  Pivot left and right.
   
  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;

#define MIN_SPEED 0
#define MAX_SPEED 200

#define ACCELERATION_RATE 2

#define FORWARD 1
#define REVERSE -1

#define LEFT 2
#define RIGHT 3

// setup is called once before the main loop executes
void setup() {
  // no setup logic required
}

// Wait for the user to press button A.
// Delay 1 second after button press.
void waitForButtonA() {
  lcd.clear();
  lcd.print("Press A");
  lcd.gotoXY(0, 1);
  lcd.print("MOTR TST");
  buttonA.waitForButton();
  delay(1000);
}

// Set speed and direction of each motor
void setVelocity(int direction, int16_t speed) {
  lcd.clear();
  lcd.println("RUNNING");
  lcd.gotoXY(0, 1);
  lcd.println("MOTR TST");
  
  switch (direction) {
    case LEFT:
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(-speed);
      break;
    case RIGHT:
      motors.setLeftSpeed(-speed);
      motors.setRightSpeed(speed);
      break;
    case FORWARD:
      motors.setSpeeds(speed, speed);
      break;
    case REVERSE:
      motors.setSpeeds(-speed, -speed);
      break;
    default:
      break;
  }
}

// Accelerate motors
void accelerate(int direction) {
  for (int speed = MIN_SPEED; speed <= MAX_SPEED; speed++) {
    setVelocity(direction, speed);
    delay(ACCELERATION_RATE);
  }
}

// Decelarate motors
void decelerate(int direction) {
  for (int speed = MAX_SPEED; speed >= MIN_SPEED; speed--) {
    setVelocity(direction, speed);
    delay(ACCELERATION_RATE);
  }
}

// Run both motors independent and together
void runMotorTest() {
  ledYellow(1);
  
  accelerate(FORWARD);
  decelerate(FORWARD);

  accelerate(REVERSE);
  decelerate(REVERSE);
  
  accelerate(LEFT);
  decelerate(LEFT);
  
  accelerate(RIGHT);
  decelerate(RIGHT);
    
  ledYellow(0);
}

// main loop
void loop() {
  waitForButtonA();
  runMotorTest();
}

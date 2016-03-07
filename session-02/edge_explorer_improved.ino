/***
  Explore space within a boundary using reflective line sensor array.
  https://www.pololu.com/docs/0J19/3

  Improved version uses random turns
   
  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;

// Tune for different lighting conditions and surfaces
// max 2000 microseconds
#define SENSOR_THRESHOLD 1000
#define SENSOR_COUNT 3
#define SENSOR_LEFT_INDEX 0
#define SENSOR_RIGHT_INDEX 2

#define MIN_SPEED 0
#define MAX_SPEED 150

#define ACCELERATION_RATE 2

#define FORWARD 1
#define REVERSE -1
#define REVERSE_TIME 500

#define LEFT 2
#define RIGHT 3

#define TURN_TIME_MAX 800
#define TURN_TIME_MIN 200

unsigned int lineSensorValues[SENSOR_COUNT];

// Wait for the user to press button A.
// Delay 1 second after button press.
void waitForButtonA() {
  lcd.clear();
  lcd.print("Press A");
  lcd.gotoXY(0, 1);
  lcd.print("EXPLORER");
  buttonA.waitForButton();
  delay(1000);
}

// Set speed and direction of each motor
void move(int direction, int16_t speed) {
  lcd.clear();
  lcd.print("XPLORING");
  lcd.gotoXY(0, 1);

  int turnTiming = 0;
  
  switch (direction) {
    case LEFT:
      turnTiming = random(TURN_TIME_MIN, TURN_TIME_MAX);
      lcd.print("Left ");
      lcd.print(turnTiming);      
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(-speed);      
      delay(turnTiming);
      break;
      
    case RIGHT:
      turnTiming = random(TURN_TIME_MIN, TURN_TIME_MAX);
      lcd.print("Right ");
      lcd.print(turnTiming);
      motors.setLeftSpeed(-speed);
      motors.setRightSpeed(speed);
      delay(turnTiming);
      break;
      
    case FORWARD:
      lcd.print("Forward");
      motors.setSpeeds(speed, speed);
      break;
      
    case REVERSE:
      lcd.print("Reverse");
      motors.setSpeeds(-speed, -speed);
      delay(REVERSE_TIME);
      break;
      
    default:
      break;
  }
}

// setup is called once before the main loop executes
void setup() {
  lineSensors.initThreeSensors();
  waitForButtonA();
}

// main loop
void loop() {
  lineSensors.read(lineSensorValues);
  
  if (lineSensorValues[SENSOR_LEFT_INDEX] < SENSOR_THRESHOLD) {
    
    // left sensor edge detected
    buzzer.playNote(NOTE_A(4), 200, 15);
    move(REVERSE, MAX_SPEED);
    move(RIGHT, MAX_SPEED);
    
  } else if (lineSensorValues[SENSOR_RIGHT_INDEX] < SENSOR_THRESHOLD) {

    // right sensor edge detected
    buzzer.playNote(NOTE_E(4), 200, 15);    
    move(REVERSE, MAX_SPEED);
    move(LEFT, MAX_SPEED);

  } else {
    // no edge detected, explore straight ahead
    move(FORWARD, MAX_SPEED);    
  }
}

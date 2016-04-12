// BPL001 Motor Control Implemenation
#include "M.h"

void M::move(int direction) {
  M::move(direction, M::MAX_SPEED);  
}

void M::move(int direction, int speed) {
  int turnTiming = 0;
  
  switch (direction) {
    case MLEFT:
      DIRECTION = M::LEFT;
      setLights(1, 0, 0);    
      motors.setLeftSpeed(speed);
      motors.setRightSpeed(-speed);
      turnTiming = random(TURN_TIME_MIN, TURN_TIME_MAX);      
      delay(turnTiming);
      break;
      
    case MRIGHT:
      DIRECTION = M::RIGHT;
      setLights(0, 0, 1);
      motors.setLeftSpeed(-speed);
      motors.setRightSpeed(speed);
      turnTiming = random(TURN_TIME_MIN, TURN_TIME_MAX);
      delay(turnTiming);
      break;
      
    case MFORWARD:
      DIRECTION = M::FORWARD;
      setLights(0, 1, 0);
      motors.setSpeeds(speed, speed);
      delay(ACCELERATE_TIME);
      break;
      
    case MREVERSE:
      DIRECTION = M::REVERSE;
      setLights(1, 1, 1);
      motors.setSpeeds(-speed, -speed);
      delay(REVERSE_TIME);
      break;
      
    default:
      break;
  }
}

int M::direction() {
  return DIRECTION;
}

void M::setLights(int yellow, int green, int red) {
  ledYellow(yellow);
  ledGreen(green);
  ledRed(red);
  return;
}

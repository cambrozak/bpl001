// Bump-n-Go by Carlos Ambrozak

// This is the final version of the Bump-n-Go program with Motor control.
// There are just a couple of lines added indicated with comments.
//
// Note that the resetXY function is called after the forward motor movement is initiated. 
// This takes advantage of the delay inside the motor logic to make sure that
// false collisions are not triggered by reversing and turning after a true collision.
//
// All motor control logic is in the M library, take a look!

// LIBRARIES
#include <Zumo32U4.h>
#include <Wire.h>
#include "M.h"

// OBJECTS
Zumo32U4ButtonA buttonA;
LSM303 lsm303;
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;

// new motor object from the M library
M m;

// FUNCTION DECLARATIONS
void waitForButtonA();
void collectSamples();
void displayData();
void resetXY();
boolean detectBump();
boolean timeWindowElapsed();
void resetTimeWindow();

// GLOBAL VARIABLES
const int SAMPLE_SIZE = 3;
long X[SAMPLE_SIZE];
long Y[SAMPLE_SIZE];
int index;

long xSum;
long ySum;
long xAverage;
long yAverage;

long lastXAverage;
long lastYAverage;
const long THRESHOLD = 2400;

unsigned long sampleWindowStartTime = 0;
const unsigned long SAMPLE_WINDOW_TIME = 900;

// SETUP
void setup() {
  waitForButtonA();
  Wire.begin();
  lsm303.init();
  lsm303.enableDefault();

  // start moving forward immediately
  // m.move has enough delay to avoide accelerometer spikes
  m.move(m.FORWARD);
  
  resetXY();
}

// MAIN LOOP
void loop() {
  collectSamples();
  displayData();

  // play a sound, reverse, turn randomly and then move forward
  // if a collision is detected, then reset the sample arrays
  if (detectBump()) {
    buzzer.playNote(NOTE_A(4), 200, 10);
    m.move(m.REVERSE);
    m.move(random(m.RIGHT, m.LEFT));
    m.move(m.FORWARD);
    resetXY();
  }
}

// detect collisions using x and y averages
boolean detectBump() {
  return (abs(xAverage - lastXAverage) >= THRESHOLD)  || (abs(yAverage - lastYAverage) >= THRESHOLD);
}

void resetTimeWindow() {
  sampleWindowStartTime = millis();
}

boolean timeWindowElapsed() {
  return ((millis() - sampleWindowStartTime) > SAMPLE_WINDOW_TIME);
}

void resetXY() {
  index = 0;
  X[index] = 0;
  Y[index] = 0;
  xSum = 0;
  ySum = 0;
  xAverage = 0;
  yAverage = 0;
  lastXAverage = 0;
  lastYAverage = 0;

  lsm303.readAcc();
  
  X[0] = (long) lsm303.a.x;
  Y[0] = (long) lsm303.a.y;

  X[0] = X[0] * X[0];
  Y[0] = Y[0] * Y[0];
   
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    X[i] = X[0];
    Y[i] = Y[0];
    xSum = xSum + X[i];
    ySum = ySum + Y[i];
  }

  xAverage = sqrt(xSum / SAMPLE_SIZE);
  yAverage = sqrt(ySum / SAMPLE_SIZE); 
  
  resetTimeWindow();
}

void collectSamples() {
  lsm303.readAcc();

  xSum = xSum - X[index];
  ySum = ySum - Y[index];
    
  X[index] = (long) lsm303.a.x;
  Y[index] = (long) lsm303.a.y;

  X[index] = X[index] * X[index];
  Y[index] = Y[index] * Y[index];

  xSum = xSum + X[index];
  ySum = ySum + Y[index];

  xAverage = sqrt(xSum / SAMPLE_SIZE);
  yAverage = sqrt(ySum / SAMPLE_SIZE);

  index++;
  index = (index < SAMPLE_SIZE) ? index : 0;

  if (timeWindowElapsed()) {
    lastXAverage = xAverage;
    lastYAverage = yAverage;
    resetTimeWindow();
  }
}

void displayData() {
  lcd.clear();
  lcd.print("X:");
  lcd.print(lsm303.a.x);
  lcd.gotoXY(0, 1);
  lcd.print("XA:");
  lcd.print(xAverage);
  delay(25);
}

void waitForButtonA() {
  lcd.clear();
  lcd.print("Press A");
  buttonA.waitForButton();
  delay(1000);
}


// Bump-n-Go by Carlos Ambrozak

// Collisions can now be detected!
// This version of the program adds just a couple of variables
// and some logic to compare averages over a time window.

// LIBRARIES
#include <Zumo32U4.h>
#include <Wire.h>

// OBJECTS
Zumo32U4ButtonA buttonA;
LSM303 lsm303;
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;

// FUNCTION DECLARATIONS
void waitForButtonA();
void collectSamples();
void displayData();
void resetXY();

// new functions to initialize the time window
void resetTimeWindow();
boolean timeWindowElapsed();

// collision detector!
boolean detectBump();

// GLOBAL VARIABLES

//const int SAMPLE_SIZE = 50;
const int SAMPLE_SIZE = 3;
long X[SAMPLE_SIZE];
long Y[SAMPLE_SIZE];
int index;

long xSum;
long ySum;

// thes variables hold the current running average values of x and y
long xAverage;
long yAverage;

// these new variables hold the averages from the start of the time window
long lastXAverage;
long lastYAverage;

// collision detected if the difference between the averages over the time window
// is greater than this threshold value.
// This is a Magic Number obtained by trial-and-error, observing the robot in the field!
const long THRESHOLD = 2400;

// this variable holds the current window start time
unsigned long sampleWindowStartTime;

// this value is the length of the time window
// This is a Magic Number obtained by trial-and-error, observing the robot in the field!
const unsigned long SAMPLE_WINDOW_TIME = 900;

// SETUP
// same setup as before
void setup() {
  waitForButtonA();
  Wire.begin();
  lsm303.init();
  lsm303.enableDefault();
  resetXY();
}

// MAIN LOOP
void loop() {
  collectSamples();
  displayData();

  // play a note if collision is detected
  // and reset the sample arrays
  if (detectBump()) {
    buzzer.playNote(NOTE_A(4), 200, 10);
    resetXY();
  }
}

// FUNCTION IMPLEMENTATIONS

// This function sets the start time for the current window to now 
void resetTimeWindow() {
  sampleWindowStartTime = millis();
}

// This function returns true if the the time window has elapsed
// otherwise it will return false to indication that
// the current time window is still in effect
boolean timeWindowElapsed() {
  return ((millis() - sampleWindowStartTime) > SAMPLE_WINDOW_TIME);
}

// This function detects a collision by comparing the
// difference between the average at the beginning of the time window
// to the average calculated right now.
// The abs function takes absolute value of the difference to insure
// that it is positive before comparing it to the threshold value
// Note that this function only considers x.  Run the robot and then add y to the logic.
boolean detectBump() {
  return (abs(xAverage - lastXAverage) >= THRESHOLD);
}

// Minor addittions to this function to initialize the starting averages
// and initialize the time window
void resetXY() {
  index = 0;
  X[index] = 0;
  Y[index] = 0;
  xSum = 0;
  ySum = 0;
  xAverage = 0;
  yAverage = 0;

  // initialize starting averages to zero
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

  // intialize the time window
  resetTimeWindow();
}

// Minor addition to this function to reset time window
// and reset starting average values at the end of each time window
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

  // starting average values to current average values
  // at the end of each time window
  if (timeWindowElapsed()) {
    lastXAverage = xAverage;
    lastYAverage = yAverage;
    resetTimeWindow();
  }
}

// same function as before
void displayData() {
  lcd.clear();
  lcd.print("X:");
  lcd.print(lsm303.a.x);
  lcd.gotoXY(0, 1);
  lcd.print("XA:");
  lcd.print(xAverage);
  delay(25);
}

// same function as before
void waitForButtonA() {
  lcd.clear();
  lcd.print("Press A");
  buttonA.waitForButton();
  delay(1000);
}


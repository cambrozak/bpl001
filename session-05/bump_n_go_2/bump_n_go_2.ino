// Bump-n-Go by Carlos Ambrozak

// Raw sensor values for x and y data vary too much to perform collision detection logic.
// The numbers oscillate rapidly between negative and positive values as seen on the LCD.
//
// This version of the program introduces two arrays to store x and y values over time
// and some math to maintain a running average of the x and y values as they are collected.
//
// Root-Mean-Square is the calculation used to obtain the average using the following steps:
// 1. Square each sample by multiplying it by itself
// 2. Add up the Squares
// 3. Divide by the number of samples
// 4. Take the square root.
//
// Root-Mean-Square insures that the average is always a meaningful positive value.
// A standard average would lose meaning in this case because negative g-force values
// would cancel the effects of positive and lessen the ability to detect sudden changes.
//
// The current and average value of x is printed to the LCD screen.
// Observe how stable the average value is compared to the current value
// during movement and standing still.
//
// Change the sample size from 3 to 50 and note the effect.

// LIBRARIES
#include <Zumo32U4.h>
#include <Wire.h>

// OBJECTS
Zumo32U4ButtonA buttonA;
LSM303 lsm303;
Zumo32U4LCD lcd;

// FUNCTION DECLARATIONS
void waitForButtonA();
void collectSamples();
void displayData();

// This function initializes x and y storage values for ongoing calculations
void resetXY();

// GLOBAL VARIABLES

// Size of the x and y sample arrays.
// Classic Time/Space tradeoff:
// The running average is more accurate with larger sample size,
// but it will take longer to initialize and calculate.
// Observe how size 3 compares to size 50
const int SAMPLE_SIZE = 50;
//const int SAMPLE_SIZE = 3;

// X and Y sample arrays
long X[SAMPLE_SIZE];
long Y[SAMPLE_SIZE];

// index for addressing values in the X and Y arrays
int index;

// running sums of x and y used to calculate the average
long xSum;
long ySum;

// running average = xSum / SAMPLE_SIZE and ySum / SAMPLE_SIZE
long xAverage;
long yAverage;

// SETUP
void setup() {
  waitForButtonA();
  Wire.begin();
  lsm303.init();
  lsm303.enableDefault();

  // initialize the X and Y arrays before executing the main loop
  resetXY();
}

// MAIN LOOP
void loop() {
  collectSamples();
  displayData();
}

// FUNCTION IMPLEMENTATIONS

// This function initalizes the X and Y arrays so that ongoing
// calculations are meaningful.
void resetXY() {

  // set everything to 0
  index = 0;
  X[index] = 0;
  Y[index] = 0;
  xSum = 0;
  ySum = 0;
  xAverage = 0;
  yAverage = 0;

  // read the Accelerometer
  lsm303.readAcc();

  // store accelerometer data in the first element of the array
  X[0] = (long) lsm303.a.x;
  Y[0] = (long) lsm303.a.y;

  // square the values by multiplying them by themselves
  X[0] = X[0] * X[0];
  Y[0] = Y[0] * Y[0];

  // this loop sets every value in the array
  // equal to the initial value collected above
  // and establishes an initial baseline sum
  // for the ongoing average calculation 
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    X[i] = X[0];
    Y[i] = Y[0];
    xSum = xSum + X[i];
    ySum = ySum + Y[i];
  }

  // as promised, Root-Mean-Square average for x and y
  // sqrt is a standard library function that takes the square root
  xAverage = sqrt(xSum / SAMPLE_SIZE);
  yAverage = sqrt(ySum / SAMPLE_SIZE); 
}

// This function is now responsible for reading, storing
// and calculating the ongoing average
void collectSamples() {

  // read the accelerometer
  lsm303.readAcc();

  // remove the effect of the value of x and y
  // that currently occupies X[index] and Y[index]
  // to make room for the newes value of x
  xSum = xSum - X[index];
  ySum = ySum - Y[index];

  // assign the newest value of x and y to X[index] and Y[index]
  X[index] = (long) lsm303.a.x;
  Y[index] = (long) lsm303.a.y;

  // square the values
  X[index] = X[index] * X[index];
  Y[index] = Y[index] * Y[index];

  // add the values to the ongoing sums
  xSum = xSum + X[index];
  ySum = ySum + Y[index];

  // as promised, Root-Mean-Square average for x and y
  // sqrt is a standard library function that takes the square root
  xAverage = sqrt(xSum / SAMPLE_SIZE);
  yAverage = sqrt(ySum / SAMPLE_SIZE);

  // increment the index to use the next value in the arrays for storage
  index++;

  // if the index is too large after incrementing, start over at the zero index
  // which is the first element in each array
  index = (index < SAMPLE_SIZE) ? index : 0;
}

// This function is adjusted to display the currenct value of x
// and the average value of x
// Observe how averaging smooths out the value over time.
void displayData() {
  lcd.clear();
  lcd.print("X:");
  lcd.print(lsm303.a.x);
  lcd.gotoXY(0, 1);
  lcd.print("XA:");
  lcd.print(xAverage);
  delay(25);
}

// this function has not changed
void waitForButtonA() {
  lcd.clear();
  lcd.print("Press A");
  buttonA.waitForButton();
  delay(1000);
}


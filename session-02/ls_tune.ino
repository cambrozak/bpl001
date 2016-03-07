/***
  Print line sensor values to LCD for tuning
  https://www.pololu.com/docs/0J19/3
   
  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4LCD lcd;

#define SENSOR_COUNT 3

unsigned int lineSensorValues[SENSOR_COUNT];

void setup() {
  lineSensors.initThreeSensors();
}

void loop() {
  lineSensors.read(lineSensorValues);

  for (int i = 0; i < SENSOR_COUNT; i++) {
    lcd.clear();
    lcd.print("Sensor ");
    lcd.print(i);
    lcd.gotoXY(0, 1);
    lcd.print(lineSensorValues[i]);
    delay(2000);
  }
}

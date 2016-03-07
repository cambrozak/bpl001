/***
  Obtain robot identity data from EEPROM and display on LCD
  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/
#include <EEPROM.h>
#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;

struct Identity {
  byte ID;
  char name[9];
};

void setup() {

}

void loop() {
  displayIdentity();
}

void displayIdentity() {

  // read identity from EEPROM
  Identity customIdentity;
  int address = 0;
  EEPROM.get(0, customIdentity);
  
  // clear screen
  lcd.clear();

  // print greeting
  lcd.print("Hi! I am");

  // go to the next line
  lcd.gotoXY(0, 1);

  // print name
  lcd.print(customIdentity.name);

  // wait three seconds
  delay(3000);

  // clear screen
  lcd.clear();

  // print ID
  lcd.print("Unique");
  lcd.gotoXY(0, 1);
  lcd.print("ID is: ");
  lcd.print(customIdentity.ID);

  // wait three seconds
  delay(3000);
}


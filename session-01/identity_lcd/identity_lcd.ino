/* This example demonstrates basic use of the Zumo 32U4 LCD.
It prints the word "hi" on the first line of the LCD and
prints the number 1234 on the second line. */
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


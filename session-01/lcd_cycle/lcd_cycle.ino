/***
  Display each character in the LCD HD44780U character table
  https://www.pololu.com/file/0J72/HD44780.pdf

  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/
#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;

void setup() {

}

void loop() {
  for (int i = 0; i < 256; i++) {
    lcd.clear();
    lcd.print(i);
    lcd.print("  ");
    lcd.print((char)i);
    lcd.print((char)i);
    lcd.gotoXY(0, 1);
    lcd.print(i);
    lcd.print("  ");
    lcd.print((char)i);
    lcd.print((char)i);
    delay(1000);
  }  
}


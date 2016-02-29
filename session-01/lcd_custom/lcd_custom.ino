
/***
  Create and display a custom character on the LCD HD44780U
  https://www.pololu.com/file/0J72/HD44780.pdf

  Character generator tool
  https://omerk.github.io/lcdchargen/

  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/
#include <Zumo32U4.h>

Zumo32U4LCD lcd;

byte customChar[8] = {
  0b00100,
  0b01110,
  0b01110,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b10101
};

void setup() {

  lcd.clear();
  
  // create a new custom character
  lcd.createChar(0, customChar);
    
  lcd.clear();
  lcd.print(0);
  lcd.print("  ");
  lcd.print((char) 0);
  lcd.print((char) 0);
  lcd.gotoXY(0, 1);
  lcd.print(0);
  lcd.print("  ");
  lcd.print((char) 0);
  lcd.print((char) 0);
}

void loop() {
  // empty loop
}

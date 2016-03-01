
/***
  Create and display a custom character animation on the LCD HD44780U
  https://www.pololu.com/file/0J72/HD44780.pdf

  Character generator tool
  https://omerk.github.io/lcdchargen/

  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/
#include <Zumo32U4.h>

Zumo32U4LCD lcd;

byte openSprite[8] = {
  0b11111,
  0b10110,
  0b11100,
  0b11001,
  0b11001,
  0b11100,
  0b11110,
  0b11111
};

byte chompSprite[8] = {
  0b11100,
  0b10110,
  0b11110,
  0b11111,
  0b11111,
  0b11110,
  0b11110,
  0b11100
};

byte backSprite[8] = {
  0b00000,
  0b00001,
  0b00011,
  0b00011,
  0b00011,
  0b00011,
  0b00001,
  0b00000
};

byte pelletSprite[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b10001,
  0b10001,
  0b00000,
  0b00000,
  0b00000
};

int BACK_SPRITE_ADDRESS = 0;
int CHOMP_SPRITE_ADDRESS = 1;
int OPEN_SPRITE_ADDRESS = 2;
int PELLET_SPRITE_ADDRESS = 3;

int SCREEN_DELAY = 1500;
int CHOMP_DELAY = 250;

int MAX_COLUMNS = 8;
int MAX_ROWS = 2;

void setup() {

  lcd.clear();
  
  // create and store sprites at specified addresses
  lcd.createChar(BACK_SPRITE_ADDRESS, backSprite);
  lcd.createChar(CHOMP_SPRITE_ADDRESS, chompSprite);
  lcd.createChar(OPEN_SPRITE_ADDRESS, openSprite);
  lcd.createChar(PELLET_SPRITE_ADDRESS, pelletSprite);
}

void loop() {
  
  showUneatenPelletScreen();
  delay(SCREEN_DELAY);
  
  // animation loop
  for (int row = 0; row < MAX_ROWS; row++) {
    for (int column = 0; column < MAX_COLUMNS; column++) {
      // backside
      lcd.gotoXY(column-1, row);
      lcd.print((char) BACK_SPRITE_ADDRESS);
      
      // chomp a pellet
      lcd.gotoXY(column, row);
      lcd.print((char) CHOMP_SPRITE_ADDRESS);
      delay(CHOMP_DELAY);

      // open mouth
      lcd.gotoXY(column, row);
      lcd.print((char) OPEN_SPRITE_ADDRESS);
      delay(CHOMP_DELAY);

      // blank for eaten pellets
      lcd.gotoXY(column-1, row);
      lcd.print("  ");
    }
  }
}

// display a screen of uneaten pellets
void showUneatenPelletScreen() {
  lcd.clear();
  printUneatenPelletRow();
  lcd.gotoXY(0, 1);
  printUneatenPelletRow();
}

// display a single row of uneaten pellets
void printUneatenPelletRow() {
  for (int i = 0; i < MAX_COLUMNS; i++) {
    lcd.print((char) PELLET_SPRITE_ADDRESS);
  }
}

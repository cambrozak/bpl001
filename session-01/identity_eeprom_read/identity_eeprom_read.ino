/***
  Retrieve robot identity data from EEPROM.

  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/

#include <EEPROM.h>

struct Identity {
  byte ID;
  char name[9];
};

void setup() {

  initializeSerialPort();
  
  Identity customIdentity;

  // eeprom memory address location for identity data
  int address = 0;

  EEPROM.get(0, customIdentity);

  Serial.println("Read identity data from EEPROM: ");
  Serial.println(customIdentity.ID);
  Serial.println(customIdentity.name);
}

void loop() {
  /* Empty loop */
}

void initializeSerialPort() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  } 
}


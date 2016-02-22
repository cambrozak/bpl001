/***
  Store robot identity data in EEPROM.

  Written by Carlos Ambrozak 2016
  Released under Creative Commmons licence.
***/

#include <EEPROM.h>

struct Identity {
  byte ID;
  char name[9];
};

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Identity customIdentity = {
    B00000001,
    "BPL-001"
  };

  // eeprom memory address location for identity data
  int address = 0;   
  
  EEPROM.put(address, customIdentity);
  
  Serial.print("Robot identity data successfully stored in EEPROM at address 0");
}

void loop() {
  /* Empty loop */
}

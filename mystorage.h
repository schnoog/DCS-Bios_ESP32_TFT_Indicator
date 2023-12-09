#ifndef __storage
#define __storage

#include <EEPROM.h>
#include "ded_data.h"

#define EEPROM_SIZE 256 // Adjust the size based on your needs


int addrLine1 = 0;
int addrLine2 = addrLine1 + 64; // Adjust based on the size of each line
int addrLine3 = addrLine2 + 64;
int addrLine4 = addrLine3 + 64;
int addrLine5 = addrLine4 + 64;

void saveToEEPROM(char *line, int addr) {
  EEPROM.begin(EEPROM_SIZE);

  // Store the length of the string
  int length = strlen(line);
  EEPROM.put(addr, length);
  addr += sizeof(int); // Move the address pointer after storing the length

  // Store the actual data
  for (int i = 0; i < length; ++i) {
    EEPROM.write(addr + i, line[i]);
  }

  EEPROM.commit();
  EEPROM.end();
}

void restoreFromEEPROM(char *&line, int addr) {
  EEPROM.begin(EEPROM_SIZE);

  // Read the length of the string
  int length;
  EEPROM.get(addr, length);
  addr += sizeof(int); // Move the address pointer after reading the length

  // Read the actual data
  char buffer[length]; // Adjust based on the expected size of each line
  for (int i = 0; i < length; ++i) {
    buffer[i] = EEPROM.read(addr + i);
  }
  line = strdup(buffer);

  EEPROM.end();
}



#endif
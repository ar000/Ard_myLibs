#ifndef ar_prog_h
#define ar_prog_h

#include "Arduino.h"
#include <EEPROM.h>

class ar_prog{
  public:
    ar_prog(uint8_t eepromAdress, uint8_t pinOutput, int8_t* h, int8_t* m);

    uint8_t getValue(uint8_t hour);
    void setValue(uint8_t hour, uint8_t mins, bool val);
    void changeValue(uint8_t hours, uint8_t mins);
    void check();
    
     
  private:
    int8_t* hour;
    int8_t* min;
    uint8_t adress;
    uint8_t prog[24];
    uint8_t pinOut;

    void updateHour(uint8_t hour);
    void updateEeprom();
    
};

#endif

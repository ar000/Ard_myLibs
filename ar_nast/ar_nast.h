#ifndef ar_nast_h
#define ar_nast_h

#include "Arduino.h"
#include <EEPROM.h>

class ar_nast{
  public:
    ar_nast(uint8_t eepromAdress, uint8_t pin, int8_t* h, int8_t* m, int16_t* t, int8_t* print);

    void check();
    void setStartTime(uint8_t h, uint8_t m);
    void setStopTime(uint8_t h, uint8_t m);
    void setTempOn(uint16_t temp);
    void setTempDelta(uint8_t plus);
    void printState();
    void TempOnUp();
    void TempOnDown();
    void deltaUp();
    void deltaDown();
    void hourStartUp();
    void hourStartDown();
    void minuteStartUp();
    void minuteStartDown();
    void hourStopUp();
    void hourStopDown();
    void minuteStopUp();
    void minuteStopDown();

   // uint8_t getProgValue(uint8_t w);

    uint8_t prog[7];
    int16_t tempOn;
    uint8_t tempDelta;

  private:
    int8_t* actualHour;
    int8_t* actualMins;
    int16_t* actualTemp;
    int8_t* printData;
    uint16_t actualTime;

    uint16_t startTime;
    uint16_t stopTime;
    uint8_t eepromAdress;

    uint8_t pinOut;
    uint8_t statePinOut;


    uint16_t naMinuty(uint8_t h, uint8_t m);
    void updateEeprom();
    void readEeprom();

    uint8_t isInTime();
};

#endif

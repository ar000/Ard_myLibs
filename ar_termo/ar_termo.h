#ifndef ar_termo_h
#define ar_termo_h
#include <avr/pgmspace.h>
#include "Arduino.h"
#include "OneWire.h"
#include "DS18B20.h"

class ar_termo{
	public:
		ar_termo(uint8_t pin);
		void read();
		int16_t zewnetrzna = 0;
		int16_t salon = 0;
		int16_t sypialnia = 0;
		int16_t agata = 0;
		int16_t bartek = 0;
		int16_t szymon = 0;
		int16_t korytarz = 0;
		int16_t wodakuchnia = 0;
		int16_t wodalazienka = 0;
		int16_t xx1 = 0;
		int16_t xx2 = 0;

  private:
		float t;
		int16_t naInt(float co);


    const byte cz_zewnetrzna[8] PROGMEM =      {0x28, 0xFF, 0x3F, 0x5C, 0x63, 0x15, 0x2, 0x87};//¿ó³to-czarny
    const byte cz_salon[8] PROGMEM =           {0x28, 0xF4, 0xAD, 0xC0, 0x6, 0x0, 0x0, 0x87};// niebieski
    const byte cz_sypialnia[8] PROGMEM =       {0x28, 0xFF, 0x17, 0x6E, 0x63, 0x15, 0x2, 0xE};//////
    const byte cz_agata[8] PROGMEM =           {0x28, 0xFF, 0x46, 0x6D, 0x63, 0x15, 0x2, 0xDE};//////
    const byte cz_bartek[8] PROGMEM =          {0x28, 0xFF, 0xFE, 0x29, 0x90, 0x15, 0x1, 0xCA};//////
    const byte cz_szymon[8] PROGMEM =          {0x28, 0x3C, 0xA3, 0xC0, 0x6, 0x0, 0x0, 0x1B};//////
    const byte cz_korytarz[8] PROGMEM =        {};//////
    const byte cz_wodakuchnia[8] PROGMEM =     {0x28, 0xFF, 0x49, 0x5D, 0x63, 0x15, 0x2, 0xF9};//do zewnetrznego
    const byte cz_wodalazienka[8] PROGMEM =    {0x28, 0xFF, 0x5, 0x4E, 0x63, 0x15, 0x2, 0x81};//br¹zowy
    const byte cz_xx1[8] PROGMEM =             {0x28, 0xFF, 0xF9, 0x7C, 0x90, 0x15, 0x1, 0xC2};//czerwony
    const byte cz_xx2[8] PROGMEM =             {0x28, 0xFF, 0xB7, 0x7D, 0x90, 0x15, 0x1, 0x6};//zielony





};

#endif

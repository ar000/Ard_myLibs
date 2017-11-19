#ifndef ar_button_pcf_h
#define ar_button_pcf_h

#include "Arduino.h"
#include <Wire.h>
#include "PCF8574.h" 
//#include "a_TimerDef.h"

#define LONG_TIME 100
class ar_button_pcf{
    public:
        ar_button_pcf(PCF8574 * pc, uint8_t pin);
        void check();
		uint8_t pcfpin;
		void (*press)(void);
		void (*long_press)(void);
    private:
		PCF8574 * pcf;
		int8_t lock;
		int8_t flag;
		uint8_t counter;
};

#endif

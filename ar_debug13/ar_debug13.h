#ifndef ar_debug13_h
#define ar_debug13_h

#include "Arduino.h"

#define LONG_TIME 100
class ar_debug13{
    public:
        ar_debug13(uint8_t pin);

        void isOk();
        void isError();
        void ar_debug13::mig(uint8_t ile);

	private:
      char myPin;
     // uint8_t count;
};

#endif

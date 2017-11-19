#ifndef ar_button_h
#define ar_button_h

#include "Arduino.h"

#define LONG_TIME 100
class ar_button{
    public:
        ar_button(uint8_t pin);
        void check();

		void (*press)(void);
		void (*long_press)(void);
    private:
		int8_t lock;
		int8_t flag;
		uint8_t counter;
		uint8_t pinn;
};

#endif

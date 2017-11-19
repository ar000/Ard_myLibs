#include "Arduino.h"
#include "ar_button.h"

ar_button::ar_button(uint8_t pin){
	pinMode(pin, INPUT_PULLUP);
	lock = 0;
	flag = 0;
	pinn = pin;
	counter = LONG_TIME;
	long_press = 0;
	press = 0;
}
void ar_button::check(){
	if(counter>0) counter--;
	uint8_t kl = !digitalRead(pinn);
	
	if(!lock && kl){
		lock = 1;
		if(press) press();
		counter = LONG_TIME;
		flag = 1;
	}else if(lock && !kl){
		lock = 0;
		flag = 0;
	}else if(flag && !counter){
		if(long_press) long_press();
		flag = 0;
	}
	
}


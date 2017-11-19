#include "Arduino.h"
#include "ar_button_pcf.h"

ar_button_pcf::ar_button_pcf(PCF8574 * pc, uint8_t pin){
    pcf = pc;
	pcfpin = pin;
	counter = LONG_TIME;
}

void ar_button_pcf::check(){
	if(counter>0) counter--;
	uint8_t kl = !pcf->digitalRead(pcfpin);
	
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


#include "Arduino.h"
#include "ar_prog.h"

ar_prog::ar_prog(uint8_t eepromAdress, uint8_t pinOutput, int8_t* h, int8_t* m){
	adress = eepromAdress;
	hour = h;
	min = m;
	pinOut = pinOutput;
	pinMode(pinOut,OUTPUT);
	for(uint8_t i = 0; i<24; i++){
        prog[i] = EEPROM.read(i+adress);
    }//ww
}

void ar_prog::updateEeprom(){
	for(uint8_t i = 0; i<24; i++){
        updateHour(i);
				//sa
    }
}

void ar_prog::updateHour(uint8_t hour){
	EEPROM.update(hour+adress, prog[hour]);
}

void ar_prog::check(){
	uint8_t  ten;
	if(*min < 10) ten = 1;
	  else if(*min < 20) ten = 2;
	  else if(*min < 30) ten = 3;
	  else if(*min < 40) ten = 4;
	  else if(*min < 50) ten = 5;
	  else  ten = 6;

	digitalWrite(pinOut, (prog[*hour] & (1 << ten)));

}
void ar_prog::changeValue(uint8_t hour, uint8_t mins){
	//boolean s = prog[hour] & (1<<mins);
	if(prog[hour] & (1<<mins))
		prog[hour] |= (1<<mins);
	else
		prog[hour] &= ~(1<<mins);
}
void ar_prog::setValue(uint8_t hours, uint8_t mins, bool val){
	if(val)
		prog[hours] |= (1<<mins);
	else
		prog[hours] &= ~(1<<mins);


}

uint8_t ar_prog::getValue(uint8_t hours){
	return prog[hours];
}

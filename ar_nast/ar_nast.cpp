#include "Arduino.h"
#include "ar_nast.h"

// moja klasa do obs³ugi nastaw

ar_nast::ar_nast(uint8_t eepromAdr, uint8_t pin, int8_t* h, int8_t* m, int16_t* t, int8_t* print){
	eepromAdress = eepromAdr;
	actualHour = h;
	actualMins = m;
	actualTemp = t;
	pinOut = pin;
	printData = print;

	pinMode(pinOut, OUTPUT);
	digitalWrite(pinOut, 0);
	statePinOut = 0;
	readEeprom();
}

void ar_nast::updateEeprom(){
	for(uint8_t i = 0; i<7; i++){
		EEPROM.update(i+eepromAdress, prog[i]);		
    }
}

void ar_nast::readEeprom(){ //8 bajtow
	for(uint8_t i = 0; i<7; i++){
		prog[i] = EEPROM.read(i+eepromAdress);
		//printData++;
		*(printData+1+i) = prog[i];
    }
	tempOn = prog[0];
	tempOn <<= 8;
	tempOn += prog[1];
	tempDelta = prog[2];
	startTime = naMinuty(prog[3], prog[4]);
	stopTime = naMinuty(prog[5], prog[6]);
}

void ar_nast::setStartTime(uint8_t h, uint8_t m){
	prog[3] = h; prog[4] = m;
	startTime = naMinuty(h,m);
}
void ar_nast::setStopTime(uint8_t h, uint8_t m){
	prog[5] = h; prog[6] = m;
	stopTime = naMinuty(h,m);
}
void ar_nast::setTempOn(uint16_t temp){
	tempOn = temp;
	prog[1] = temp;
	prog[0] = temp >> 8;
	tempOn = prog[0];
	tempOn <<= 8;
	tempOn += prog[1];
}
void ar_nast::setTempDelta(uint8_t plus){
	tempDelta = plus;
	prog[2] = plus;
}

void ar_nast::check(){
	actualTime = naMinuty(*actualHour, *actualMins);
	if(!statePinOut){
		if(*actualTemp <= tempOn && isInTime()){
			statePinOut = 1;
			digitalWrite(pinOut,statePinOut);
		}
	}else{
		if(*actualTemp >= tempOn + tempDelta || !isInTime()){
			statePinOut = 0;
			digitalWrite(pinOut,statePinOut);
		}
	}

	printState();
}

uint8_t ar_nast::isInTime(){
	 boolean x = 0;

	    if(stopTime > startTime){
	            if(actualTime >= startTime && actualTime < stopTime) {
	                x=1;
	            }	            else{
	                 //if(minutaDnia >= zal || (minutaDnia >= 0 && minutaDnia < wyl)) x=1;
	            }
	    }else{
	        //PL("czas jest dziwny");
	        if(actualTime >= startTime || (actualTime >= 0 && actualTime < stopTime)) x = 1;
	    }
	    return x;
}

void ar_nast::printState(){

	Serial.print("a:");
	Serial.print(tempOn);
	Serial.print(":");Serial.print(tempDelta);
	Serial.print(":");Serial.print(*actualTemp);

	Serial.print(":");Serial.print(startTime);
	Serial.print(":");Serial.print(stopTime);
	Serial.print(":");Serial.print(actualTime);

	Serial.print(":");Serial.print(statePinOut);
	Serial.println();
}
uint16_t ar_nast::naMinuty(uint8_t h, uint8_t m){
	return (h*60) + m;
}
void ar_nast::TempOnUp(){
	tempOn += 5;
	if(tempOn > 700) tempOn = 0;
	setTempOn(tempOn);
}
void ar_nast::TempOnDown(){
	tempOn -= 5;
	if(tempOn < 0) tempOn = 400;
	setTempOn(tempOn);
}
void ar_nast::deltaUp(){
	tempDelta += 5;
	if(tempDelta > 250) tempDelta = 5;
	setTempDelta(tempDelta);
}
void ar_nast::deltaDown(){
	tempDelta -= 5;
	if(tempDelta < 5) tempDelta = 35;
	setTempDelta(tempDelta);
}
void ar_nast::hourStartUp(){
	prog[3]++;
	if(prog[3]>23) prog[3]=0;
	setStartTime(prog[3], prog[4]);
}
void ar_nast::hourStartDown(){
	if(prog[3]==0) prog[3]==24;
	prog[3]--;
	setStartTime(prog[3], prog[4]);
}
void ar_nast::minuteStartUp(){
	prog[4]++;
	if(prog[4]>59) prog[4]=0;
	setStartTime(prog[3], prog[4]);
}
void ar_nast::minuteStartDown(){
	if(prog[4]==0) prog[4]==59;
	prog[4]--;
	setStartTime(prog[3], prog[4]);
}

void ar_nast::hourStopUp(){
	prog[5]++;
	if(prog[5]>23) prog[5]=0;
	setStartTime(prog[5], prog[6]);
}
void ar_nast::hourStopDown(){
	if(prog[5]==0) prog[5]==24;
	prog[5]--;
	setStartTime(prog[5], prog[6]);
}
void ar_nast::minuteStopUp(){
	prog[6]++;
	if(prog[6]>59) prog[6]=0;
	setStartTime(prog[5], prog[6]);
}
void ar_nast::minuteStopDown(){
	if(prog[6]==0) prog[6]==59;
	prog[6]--;
	setStartTime(prog[5], prog[6]);
}

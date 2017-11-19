#include "Arduino.h"
#include "a_Ledy.h"


a_Ledy::a_Ledy(){
    panel = new LedControl(12,11,10,2);
	panel->clearDisplay(0);
    panel->clearDisplay(1);
	panel->setIntensity(0,0);
    panel->setIntensity(1,0);
    panel->shutdown(0,false);
    panel->shutdown(1,false);
	DDRD |= (1<<3);//pinMode(3,OUTPUT)
	for(uint8_t w = 0; w < 12; w++){
		setDigit(w,15);
	}
	blinkCount=7;
	//patternLed[LED_AL1] = 255;
	caseBright = 1;
}
void a_Ledy::blinkPlus(){
	bPlus = 2;
}
void a_Ledy::blinkMinus(){
	bMinus = 2;
}
void a_Ledy::blinkSleep(){
	bSleep = 2;
}
void a_Ledy::blinkIrda(){
	bIrda = 2;
}
void a_Ledy::blinkPower(){
	bPower = 2;
}
void a_Ledy::blinkZegar(){
	bZegar = 2;
}
void a_Ledy::show(){
	migCount++;
	if(migCount == 10){
		mig = !mig;
		migCount = 0;
	}
	tickCount++;
	if(bPlus>0){
		ledy2 |= (1<<4);
		bPlus--;
	}else{
		ledy2 &= ~(1<<4);
	}
	if(bMinus>0){
		ledy2 |= (1<<7);
		bMinus--;
	}else{
		ledy2 &= ~(1<<7);
	}
	if(bPower>0){
		ledy1 |= (1<<6);
		bPower--;
	}
	if(bSleep>0){
		ledy1 |= (1<<2);
		bSleep--;
	}else{
		//if(patternLed[LED_SLEEP]==0) ledy1 &= ~(1<<2);
	}
	if(bZegar>0){
		ledy2 |= (1<<2);
		bZegar--;
	}
	if(bIrda>0){
		ledy2 |= (1<<3);
		bSleep--;
	}else{
		if(patternLed[LED_IRREC]==0) ledy2 &= ~(1<<3);
	}
	if(tickCount > 5){	//5 to będzie 125ms  4* to 0,5s
	//mig = !mig;
		tickCount = 0;
		blinkCount--;
		if(blinkCount < 0) blinkCount = 7;
		
		if(patternLed[LED_DOTS] & (1<<blinkCount)) ledy1 |= (1<<3|1<<1);
		else ledy1 &= ~(1<<3|1<<1);
		if(patternLed[LED_POWER] & (1<<blinkCount)) ledy1 |= (1<<6);
		else ledy1 &= ~(1<<6);
		if(patternLed[LED_SLEEP] & (1<<blinkCount)) ledy1 |= (1<<2);
		else ledy1 &= ~(1<<2);
		if(patternLed[LED_CLOCK] & (1<<blinkCount)) ledy2 |= (1<<2);
		else ledy2 &= ~(1<<2);
		if(patternLed[LED_IRDA] & (1<<blinkCount)) ledy2 |= (1<<3);
		else ledy2 &= ~(1<<3);
		if(patternLed[LED_MINUS] & (1<<blinkCount)) ledy2 |= (1<<7);
		else ledy2 &= ~(1<<7);
		if(patternLed[LED_PLUS] & (1<<blinkCount)) ledy2 |= (1<<4);
		else ledy2 &= ~(1<<4);
		if(patternLed[LED_AL1] & (1<<blinkCount)) ledy2 |= (1<<0);
		else ledy2 &= ~(1<<0);
		if(patternLed[LED_AL2] & (1<<blinkCount)) ledy2 |= (1<<5);
		else ledy2 &= ~(1<<5);
		if(patternLed[LED_AL3] & (1<<blinkCount)) ledy2 |= (1<<1);
		else ledy2 &= ~(1<<1);
		if(patternLed[LED_AL4] & (1<<blinkCount)) ledy2 |= (1<<6);
		else ledy2 &= ~(1<<6);
		if(patternLed[LED_IRREC] & (1<<blinkCount)) ledy1 |= (1<<5);
		else ledy1 &= ~(1<<5);
	}
    panel->setRow(1,0,ledy1);
	panel->setRow(1,3,ledy2);
	
	for(uint8_t e=0; e<12; e++){
		uint8_t k,p;
		if(e<8){
			k = 0;
			p = 7-e;
		}else{
			k = 1;
			p = 15 - e;
		}
		uint8_t t = digit[e];
		t &= ~(1<<7|1<<6|1<<5|1<<4);
		if(t<15){
			if(digit[e] & (1<<6)  && mig){
				panel->setChar(k,p,' ',digit[e] & (1<<7));
			
			}else{
				if(e==0 && t>9){
					//Serial.println("a");
					if(t == 10) panel->setChar(k,p,' ',digit[e] & (1<<7));
					else if(t==11) setpk1();
					else if(t==12) setpk2();
					else if(t==13) setpk3();
				}else{
					panel->setDigit(k,p,t,digit[e] & (1<<7));
				}
			}
		}else{
			panel->setChar(k,p,' ',digit[e] & (1<<7));
		}
	}
	
	analogWrite(3,caseBright);
}
//bit 6 - góra
//bit 3 - dół
//bit 0 - środek
void a_Ledy::setpk1(){
	byte e = B01000000;
	panel->setRow(0,7,e);
}
void a_Ledy::setpk2(){
	byte e = B00000001;
	panel->setRow(0,7,e);
}
void a_Ledy::setpk3(){
	byte e = B01000001;
	panel->setRow(0,7,e);
}

void a_Ledy::ledyOff(){
	for(byte a=3; a<12; a++){
		patternLed[a] = 0;
	}
}
void a_Ledy::setBright(int8_t b){	//0-15
    panel->setIntensity(0,b);
    panel->setIntensity(1,b);
}

void a_Ledy::setDigit(uint8_t a, uint8_t x){
	if( x>15 ) x = 15;
	digit[a] &= ~(1<<3 | 1<<2 | 1<<1 | 1<<0);
	digit[a] |= x;
}
void a_Ledy::clearDots(){
	setKd1(false);setKd2(false);setKd3(false);
    setKd4(false);setKd5(false);setKd6(false);
    setKd7(false);setKd8(false);setKg1(false);
    setKg2(false);setKg3(false);setKg4(false);
}
void a_Ledy::setD1(byte b){
	setDigit(0,b);
}
void a_Ledy::setD2(byte b){
	setDigit(1,b);
}
void a_Ledy::setD3(byte b){
	setDigit(2,b);
}
void a_Ledy::setD4(byte b){
	setDigit(3,b);
}
void a_Ledy::setD5(byte b){
	setDigit(4,b);
}
void a_Ledy::setD6(byte b){
	setDigit(5,b);
}
void a_Ledy::setD7(byte b){
	setDigit(6,b);
}
void a_Ledy::setD8(byte b){
	setDigit(7,b);
}
void a_Ledy::setG1(byte b){
	setDigit(8,b);
}
void a_Ledy::setG2(byte b){
	setDigit(9,b);
}
void a_Ledy::setG3(byte b){
	setDigit(10,b);
}
void a_Ledy::setG4(byte b){
	setDigit(11,b);
}
void a_Ledy::setDot(uint8_t a, bool x){
	if(x){
		digit[a] |= (1<<7);
	}else{
		digit[a] &= ~(1<<7);
	}
}
void a_Ledy::setBlink(uint8_t a, bool x){
	if(x){
		digit[a] |= (1<<6);
	}else{
		digit[a] &= ~(1<<6);
	}
}
void a_Ledy::noBlinkDigit(){
	for(byte f = 0; f<12; f++){
		setBlink(f,false);
	}
}
void a_Ledy::setKd1(bool b){
	setDot(0,b);
}
void a_Ledy::setKd2(bool b){
	setDot(1,b);
}
void a_Ledy::setKd3(bool b){
	setDot(2,b);
}
void a_Ledy::setKd4(bool b){
	setDot(3,b);
}
void a_Ledy::setKd5(bool b){
	setDot(4,b);
}
void a_Ledy::setKd6(bool b){
	setDot(5,b);
}
void a_Ledy::setKd7(bool b){
	setDot(6,b);
}
void a_Ledy::setKd8(bool b){
	setDot(7,b);
}
void a_Ledy::setKg1(bool b){
	setDot(8,b);
}
void a_Ledy::setKg2(bool b){
	setDot(9,b);
}
void a_Ledy::setKg3(bool b){
	setDot(10,b);
}
void a_Ledy::setKg4(bool b){
	setDot(11,b);
}

void a_Ledy::setCaseBright(uint8_t b){
	caseBright = b;
}
void a_Ledy::testAll(){
    setD1(8);
    setD2(8);
    setD3(8);
    setD4(8);
    setD5(8);
    setD6(8);
    setD7(8);
    setD8(8);
    setG1(8);
    setG2(8);
    setG3(8);
    setG4(8);

    setKd1(true);
    setKd2(true);
    setKd3(true);
    setKd4(true);
    setKd5(true);
    setKd6(true);
    setKd7(true);
    setKd8(true);
    setKg1(true);
    setKg2(true);
    setKg3(true);
    setKg4(true);
    
    setCaseBright(2);
}

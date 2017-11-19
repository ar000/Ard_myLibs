#ifndef a_Ledy_h
#define a_Ledy_h

#include "Arduino.h"
#include "LedControl.h"
#include "a_TimerDef.h"

class a_Ledy{
    public:
        a_Ledy();
        void show();
		void blinkPlus();
		void blinkMinus();
		void blinkSleep();
		void blinkIrda();
		void blinkPower();
		void blinkZegar();
        void setBright(int8_t b);//0-15
		void ledyOff();

		void setD1(byte b);
		void setD2(byte b);
		void setD3(byte b);
		void setD4(byte b);
		void setD5(byte b);
		void setD6(byte b);
		void setD7(byte b);
		void setD8(byte b);
		void setG1(byte b);
		void setG2(byte b);
		void setG3(byte b);
		void setG4(byte b);
		void setKd1(bool b);
		void setKd2(bool b);
		void setKd3(bool b);
		void setKd4(bool b);
		void setKd5(bool b);
		void setKd6(bool b);
		void setKd7(bool b);
		void setKd8(bool b);
		void setKg1(bool b);
		void setKg2(bool b);
		void setKg3(bool b);
		void setKg4(bool b);
		void setPK1(bool b);
		void setPK2(bool b);

		void setCaseBright(uint8_t b);
		void testAll();
		void clearDots();
		uint8_t patternLed[12];
		
		void setBlink(uint8_t a, bool x);
		void noBlinkDigit();
	
    private:
		void setDigit(uint8_t a, uint8_t x);
		void setDot(uint8_t a, bool x);
		//void setBlink(uint8_t a, bool x);
		void setpk1();
		void setpk2();
		void setpk3();
		void lewa(int8_t p, int8_t b);
		void prawa(int8_t p, int8_t b);
        uint8_t ledy1;	//x,power,irda,kropka1,x,sleep,kropka2,migDots
        uint8_t ledy2;	//p1,p2,p3,p4,minus,plus,pilot,zegar
		LedControl * panel;
		uint8_t caseBright;
		uint8_t digit[12];
		uint8_t tickCount;
		int8_t blinkCount;
		bool mig;
		int8_t migCount;
		uint8_t bSleep, bPlus, bMinus, bIrda, bPower, bZegar;
};

#endif
//Row 0
//B01000000 - power
//B00100000 - IR
//B00001000 - kropka1
//B00000100 - sleep
//B00000010 - kropka2
//B00000001 - mig kropek
//-----------------------
//Row 3
//B10000000 - minus
//B01000000 - p4
//B00100000 - p2
//B00010000 - plus
//B00001000 - pilot
//B00000100 - zegar
//B00000010 - p3
//B00000001 - p1
//----------------------
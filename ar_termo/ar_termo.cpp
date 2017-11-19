#include "Arduino.h"
#include "ar_termo.h"

DS18B20* czujniki;



ar_termo::ar_termo(uint8_t pin){
	t=0;

	OneWire wire(pin);
	*czujniki = DS18B20(&wire);
	czujniki->begin();
	czujniki->request();
}

void ar_termo::read(){
	if(czujniki->available()){
		t = czujniki->readTemperature(FA(cz_salon));
		if(t<75) salon = naInt(t);
		t = czujniki->readTemperature(FA(cz_agata));
		if(t<75) agata = naInt(t);
		t = czujniki->readTemperature(FA(cz_bartek));
		if(t<75) bartek = naInt(t);
		t = czujniki->readTemperature(FA(cz_korytarz));
		if(t<75) korytarz = naInt(t);
		t = czujniki->readTemperature(FA(cz_sypialnia));
		if(t<75) sypialnia = naInt(t);
		t = czujniki->readTemperature(FA(cz_szymon));
		if(t<75) szymon = naInt(t);
		t = czujniki->readTemperature(FA(cz_wodakuchnia));
		if(t<75) wodakuchnia = naInt(t);
		t = czujniki->readTemperature(FA(cz_wodalazienka));
		if(t<75) wodalazienka = naInt(t);
		t = czujniki->readTemperature(FA(cz_zewnetrzna));
		if(t<75) zewnetrzna = naInt(t);
		t = czujniki->readTemperature(FA(cz_xx1));
		if(t<75) xx1 = naInt(t);
		t = czujniki->readTemperature(FA(cz_xx2));
		if(t<75) xx2 = naInt(t);

	}
	agata = 122;
	bartek = 123;			//122 ???
	szymon = 124;
	salon = 123;
	sypialnia = -123;
	korytarz = 254;
	wodakuchnia = 157;
	wodalazienka = 27;
	zewnetrzna = -14;
	xx1 = 255;
	xx2 = -1;




}

int16_t ar_termo::naInt(float co){
	  if(co < -99.9) return -999;
	  else if(co > 99.9) return 999;
	  else return co*10;
}




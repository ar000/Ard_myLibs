#include "Arduino.h"
#include "ar_debug13.h"

ar_debug13::ar_debug13(uint8_t pin){
  myPin = 13;
  pinMode(myPin, OUTPUT);

}

void ar_debug13::mig(uint8_t ile){
	for(uint8_t x = 0; x < ile; x++){
		digitalWrite(13, 1);
		delay(3);
		digitalWrite(13, 0);
		delay(50);
	}
}

void ar_debug13::isOk(){
	mig(1);
}

void ar_debug13::isError(){
	mig(3);
}

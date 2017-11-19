#ifndef a_TimerDef_h
#define a_TimerDef_h
#include "Arduino.h"
//inne
#define PK1 6
#define PK2 7
#define FR A1 
#define PK1_ON PORTD |= (1<<PK1)
#define PK2_ON PORTD |= (1<<PK2)
#define PK1_OFF PORTD &= ~(1<<PK1)
#define PK2_OFF PORTD &= ~(1<<PK2)
// ekrany
#define S_HOME 0
#define S_HOME_SET 1
#define S_DAYOFWEEK 2
	#define SET_CLOCK 60
	#define SET_CLOCK_HH 61
	#define SET_CLOCK_MM 62
	#define SET_CLOCK_YY 63
	#define SET_CLOCK_MO 64
	#define SET_CLOCK_DD 65
	#define SET_CLOCK_DW1 66
	#define SET_CLOCK_DW2 67
	#define SET_CLOCK_DW3 68
	#define SET_CLOCK_DW4 69
	#define SET_CLOCK_DW5 70
	#define SET_CLOCK_DW6 71
	#define SET_CLOCK_DW7 72
#define S_SLEEP 5
#define S_AL1_TIME 10
#define S_AL1_SLEEP 11
#define S_AL2_TIME 20
#define S_AL2_SLEEP 21
#define S_AL3_TIME 30
#define S_AL3_SLEEP 31
#define S_AL4_TIME 40
#define S_AL4_SLEEP 41
//klawisze
#define K_ZEGAR 1
#define K_IRDA 2
#define K_SET 2
#define K_MINUS 3
#define K_PLUS 4
#define K_P1 5
#define K_P2 6
#define K_P3 7
#define K_P4 8
#define K_POWER 9
#define K_SLEEP 10
//ledy
#define LED_DOTS 0
#define LED_POWER 1
#define LED_SLEEP 2
#define LED_CLOCK 3
#define LED_IRDA 4
#define LED_MINUS 5
#define LED_PLUS 6
#define LED_AL1 7
#define LED_AL2 8
#define LED_AL3 9
#define LED_AL4 10
#define LED_IRREC 11

//
#endif

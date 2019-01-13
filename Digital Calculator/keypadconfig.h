/*
 * keypadconfig.h
 *
 * Created: 9/8/2017 11:45:01 AM
 *  Author: Ramy Elfouly
 */ 



#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_
 
 #define USE_AVR
 //#define USE_ARM

#ifndef USE_AVR
#ifndef USE_ARM
#error "A Traget has to be defined Available TARget are: USE_AVR or USE_ARM "
#endif
#endif

#ifdef USE_AVR
#ifdef USE_ARM
	#error "you can't use avr and arm at the same time"
#endif
#endif
#ifdef USE_AVR
 #include <avr/io.h>
#endif

 #ifdef USE_ARM
#define ROW0_DEN			GPIOF->DEN
 #endif
#define ROW0				0
#define ROW0_OUTPUTDATA		PORTB
#define ROW0_DIR			DDRB

#define ROW1				1
#define ROW1_OUTPUTDATA		PORTB
#define ROW1_DIR			DDRB

#define ROW2				2
#define ROW2_OUTPUTDATA		PORTB
#define ROW2_DIR			DDRB

#define ROW3				3
#define ROW3_OUTPUTDATA		PORTB
#define ROW3_DIR			DDRB

#define LINE0				4
#define LINE0_DATAIN		PINB
#define LINE0_DIR			DDRB
#define LINE0_PULLUP		PORTB

#define LINE1				5
#define LINE1_DATAIN		PINB
#define LINE1_DIR			DDRB
#define LINE1_PULLUP		PORTB

#define LINE2				6
#define LINE2_DATAIN		PINB
#define LINE2_DIR			DDRB
#define LINE2_PULLUP		PORTB

#define LINE3				7
#define LINE3_DATAIN		PINB
#define LINE3_DIR			DDRB
#define LINE3_PULLUP		PORTB

#endif /* KEYPADCONFIG_H_ */
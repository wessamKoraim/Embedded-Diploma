/*
 * keypad.h
 *
 * Created: 9/8/2017 11:15:05 AM
 *  Author: Ramy Elfouly
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypadconfig.h"
#define NO_VALID_INPUT			0xFF

#define ALL_LINES_CHECK			((LINE0_DATAIN&(1<<LINE0))\
							  &&(LINE1_DATAIN&(1<<LINE1))\
							  &&(LINE2_DATAIN&(1<<LINE2))\
							  &&(LINE3_DATAIN&(1<<LINE3)))	


void vKeypadInit(void);
unsigned char ucKeypadScan(void);



#endif /* KEYPAD_H_ */
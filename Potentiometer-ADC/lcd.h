/*
 * lcd.h
 *
 * Created: 9/16/2017 7:33:31 PM
 *  Author: Wesam
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL

#define LINE_1		1
#define LINE_2		2

#define ELEMENT_1   0
#define ELEMENT_2	1
#define ELEMENT_3	2
#define ELEMENT_4	3
#define ELEMENT_5	4
#define ELEMENT_6	5
#define ELEMENT_7	6
#define ELEMENT_8	7
#define ELEMENT_9	8
#define ELEMENT_10  9
#define ELEMENT_11 10
#define ELEMENT_12 11
#define ELEMENT_13 12
#define ELEMENT_14 13
#define ELEMENT_15 14
#define ELEMENT_16 15

#include <avr/io.h>
#include <util/delay.h>
#include "lcdConfig.h"

typedef unsigned char uint_8_bits;
void vLcdInit (void);
void vSendChar(uint_8_bits character);
void vCommand(uint_8_bits command);
void vSendString(uint_8_bits *character, uint_8_bits size);
void vClearLcd(void);
void vGoto_XY(uint_8_bits x, uint_8_bits y);
void vNumToChar(int num);

#endif /* LCD_H_ */
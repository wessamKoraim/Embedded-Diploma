/*
 * sendCharacter.c
 *
 * Created: 9/18/2017 3:37:32 PM
 *  Author: Wesam
 */ 

#include "lcd.h"

void vSendChar(uint_8_bits character)
{
	RS_OUTPUT_DATA |=   (1<<RS);
	RW_OUTPUT_DATA &=  ~(1<<RW);
	vCommand(character & 0xF0);
	_delay_us(100);
	character = character << 4;
	vCommand(character & 0xF0);
	_delay_us(100);
}
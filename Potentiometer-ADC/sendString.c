/*
 * sendString.c
 *
 * Created: 9/18/2017 8:24:23 PM
 *  Author: Wesam
 */ 
 #include "lcd.h"
 void vSendString(uint_8_bits *character, uint_8_bits size)
 {
	uint_8_bits i;
	if (size > 15)
	{
		for (i = 0; i < 16; i++)
		{
			vSendChar(*(character+i));
		}
		RS_OUTPUT_DATA &= ~(1<<RS);
		vCommand(0xC0);
		_delay_ms(1);
		vCommand(0x00);
		_delay_ms(1);
		for (i = 16; i < size; i++)
		{
			vSendChar(*(character+i));
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			vSendChar(*(character+i));
		}
	}
	
 }
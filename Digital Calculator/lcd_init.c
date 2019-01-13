/*
 * lcd_init.c
 *
 * Created: 9/15/2017 3:35:03 AM
 *  Author: Wesam
 */

 #include "lcd.h"

 void vLcdInit (void)
 {
	//set all data pins, register select and read/write to be output

	D4_DIRECTION |= (1<<D4);
	D5_DIRECTION |= (1<<D5);
	D6_DIRECTION |= (1<<D6);
	D7_DIRECTION |= (1<<D7);

	RS_DIRECTION |= (1<<RS);
	RW_DIRECTION |= (1<<RW);
	EN_DIRECTION |= (1<<EN);

	//wait for 15 ms just after power on
	_delay_ms(35);

	//set Register Select and Read/Write to ZERO
	RW_OUTPUT_DATA  &= ~(1<<RW);
	RS_OUTPUT_DATA  &= ~(1<<RS);

	//first command
	vCommand(0x30);

	_delay_ms(10);

	//second command
	vCommand(0x30);

	_delay_ms(1);

	//third command
	vCommand(0x30);

	_delay_ms(1);

	//fourth command
	vCommand(0x20);

	_delay_ms(1);

	//fifth command to set 4 bit mode
	vCommand(0x20);

	_delay_ms(1);

	vCommand(0x80);

	_delay_ms(1);

	//sixth command
	vCommand(0x00);

	_delay_ms(1);

	vCommand(0x80);

	_delay_ms(1);

	//clear screen
	vClearLcd();

	//eighth command
	vCommand(0x00);

	_delay_ms(1);

	vCommand(0x60);

	_delay_ms(1);

	//Display ON
	vCommand(0x00);

	_delay_ms(1);

	vCommand(0xE0);

	_delay_ms(1);

	//set DDRAM ADDRESS TO 0x80
	vCommand(0x80);

	_delay_ms(1);

	vCommand(0x00);

	_delay_ms(1);
 }

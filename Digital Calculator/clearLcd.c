/*
 * clearLcd.c
 *
 * Created: 9/18/2017 9:06:05 PM
 *  Author: Wesam
 */ 
 #include "lcd.h"
 void vClearLcd(void)
 {
	RS_OUTPUT_DATA &= ~(1<<RS);
	vCommand(0x00);
	_delay_ms(1);
	vCommand(0x10);
	_delay_ms(1);
 }
/*
 * lcdCommands.c
 *
 * Created: 9/18/2017 5:58:50 PM
 *  Author: Wesam
 */ 

 #include "lcd.h"

 void vCommand(uint_8_bits command)
 {

	if((command & (1<<D7))==0)
	{
		D7_OUTPUT_DATA &= ~(1<<D7);
	}
	else
	{
		D7_OUTPUT_DATA |=  (1<<D7);
	}
	//##########################################
	if((command & (1<<D6))==0)
	{
		D6_OUTPUT_DATA &= ~(1<<D6);
	}
	else
	{
		D6_OUTPUT_DATA |=  (1<<D6);
	}
	//##########################################
	if((command & (1<<D5))==0)
	{
		D5_OUTPUT_DATA &= ~(1<<D5);
	}
	else
	{
		D5_OUTPUT_DATA |=  (1<<D5);
	}
	//##########################################
	if((command & (1<<D4))==0)
	{
		D4_OUTPUT_DATA &= ~(1<<D4);
	}
	else
	{
		D4_OUTPUT_DATA |=  (1<<D4);
	}
	EN_OUTPUT_DATA |=  (1<<EN);
	EN_OUTPUT_DATA &= ~(1<<EN);
 }
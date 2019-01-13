/*
 * gotoXY.c
 *
 * Created: 9/18/2017 9:14:14 PM
 *  Author: Wesam
 */ 

 #include "lcd.h"
 const char errorMessageY[] = "Error, Y is 1 or 2 ONLY";
 const char errorMessageX[] = "Error, 0<X<15";
 void vGoto_XY(uint_8_bits x, uint_8_bits y)
 {
	uint_8_bits i;
	RS_OUTPUT_DATA &= ~(1<<RS);
	vCommand(0x00);
	_delay_us(100);
	vCommand(0x20);
	_delay_ms(5);
	if (y==1)
	{
		if ( (x < (uint_8_bits) 0) || (x > (uint_8_bits) 15) )
		{
			vSendString(errorMessageX,sizeof(errorMessageX)-(uint_8_bits)1);
		}
		else
		{
			vCommand(0x80);
			_delay_ms(1);
			vCommand(0x00);
			_delay_ms(5);

			for (i = 0; i < x; i++)
			{
				vCommand(0x10);
				_delay_ms(1);
				vCommand(0x40);
				_delay_ms(1);
			}
		}
	}
	else if(y==2)
	{
		if ( (x < (uint_8_bits) 0) || (x > (uint_8_bits) 15) )
		{
			vSendString(errorMessageX,sizeof(errorMessageX)-(uint_8_bits)1);
		}
		else
		{
			vCommand(0xC0);
			_delay_ms(1);
			vCommand(0x00);
			_delay_ms(5);

			for (i = 0; i < x; i++)
			{
				vCommand(0x10);
				_delay_ms(1);
				vCommand(0x40);
				_delay_ms(1);
			}
		}
	}
	else
	{
		vSendString(errorMessageY,sizeof(errorMessageY)-(uint_8_bits)1);
	}
 }
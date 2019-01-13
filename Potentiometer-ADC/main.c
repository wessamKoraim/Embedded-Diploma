/*
 * ADC.c
 *
 * Created: 10/6/2017 6:00:03 AM
 * Author : Wesam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include <util/delay.h>


int main(void)
{
    //DEFINE A VARIABLE TO CARRY THE READING
	int reading = 0;
	//SET DIRECTION OF PIN#0 IN PORTA AS INPUT
    DDRA   &=~ (1U<<0);
    //SET PRESCALER VALUE TO 8
    ADCSRA &=~(1U<<ADPS2);
    ADCSRA |= (1U<<ADPS1)|(1U<<ADPS0);
    //SET REFERENCE VOLTAGE TO BE AREF
    ADMUX  |= (1U<<REFS0);
	ADMUX  &=~(1U<<REFS1);
    //SELECT INPUT CHANNEL TO BE CHANNEL 0 -> PIN#0 IN PORTA
    ADMUX  &=~ ( (1U<<MUX0) | (1U<<MUX1) | (1U<<MUX2) | (1U<<MUX3) | (1U<<MUX4) );
	//SET RIGHT ALIGNMENT
	ADMUX  &=~(1U<<ADLAR);
	//SET ENABLE BIT IN THE ADC STATUS REGISTER
	ADCSRA |= (1U<<ADEN);
	//INITIALIZE THE LCD
	vLcdInit();
    while (1) 
    {
		//START CONVERSION
		ADCSRA |= (1U<<ADSC);
		//WAIT FOR CONVERSION
		while ( (ADCSRA & (1U<<ADSC)) == 1 );
		ADCSRA |= (1<<ADIF);
		//SEND THE READING TO THE LCD
		reading = (ADCL) | (ADCH<<8);
		vNumToChar(reading);
		_delay_ms(1);
		vClearLcd();
		_delay_ms(1);
    }
	return 0;
}


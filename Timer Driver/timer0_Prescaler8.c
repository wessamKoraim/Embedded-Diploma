/*
 * timer0_Prescaler8.c
 *
 * Created: 9/29/2017 4:23:05 PM
 *  Author: Wesam
 */ 

#include "timer.h"


void timer0_Prescaler8(uint16_t counter)
{
	//REMOVE EXTRA 19 CYCLES FROM UNKNOWN SOURCE
	//counter =  MAX_PRE_SCALER_8 - counter; // counter = 1739
	TIMSK |=  (1U<<TOIE0);
	counter /= 8; 
	//SET COUNTER OF THE TIMER TO START FROM SET VALUE
	TCNT0 =  0xFF - counter;
	//ENABLE TIMER-0 AND SET PRESCALAR = 8
	TCCR0 &=~  (1U<<CS00);
	TCCR0 |=   (1U<<CS01);
	TCCR0 &=~  (1U<<CS02);
	//SET WG00 = 0 AND WG01 = 0 FOR NORMAL MODE
	TCCR0 &=~ (1U<<WGM01);
	TCCR0 &=~ (1U<<WGM00);
	//ENABLE TIMER-0 OVER FLOW INTERRUPT FLAG
}
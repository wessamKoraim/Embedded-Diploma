/*
 * timer0_Prescaler8.c
 *
 * Created: 9/29/2017 4:23:05 PM
 *  Author: Wesam
 */ 

#include "timer.h"

void timer0_Prescaler1024(uint32_t counter)
{
	counter /= 1024;
	//REMOVE EXTRA 19 CYCLES FROM UNKNOWN SOURCE
	counter =  0xFF - counter;
	//SET COUNTER OF THE TIMER TO COUNTER VARIABLE
	TCNT0 =  counter;
	//ENABLE TIMER-0 AND SET PRESCALAR = 1
	TCCR0 |=   (1U<<CS00);
	TCCR0 &=~  (1U<<CS01);
	TCCR0 |=   (1U<<CS02);
	//SET WG00 = 0 AND WG01 = 0 FOR NORMAL MODE
	TCCR0 &=~ (1U<<WGM01);
	TCCR0 &=~ (1U<<WGM00);
	//ENABLE TIMER-0 OVER FLOW INTERRUPT FLAG
	TIMSK |=  (1U<<TOIE0);
}
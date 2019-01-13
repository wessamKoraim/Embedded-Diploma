/*
 * timer0_Prescaler8.c
 *
 * Created: 9/29/2017 4:23:05 PM
 *  Author: Wesam
 */ 

#include "timer.h"

void timer0_Prescaler64(uint16_t counter)
{
	counter /= 64;
	//REMOVE EXTRA 19 CYCLES FROM UNKNOWN SOURCE
	counter =  0xFF - counter;
	//SET COUNTER OF THE TIMER TO COUNTER VARIABLE
	TCNT0 =  counter;
	//ENABLE TIMER-0 AND SET PRESCALAR = 64
	TCCR0 |=   (1<<CS00);
	TCCR0 |=   (1<<CS01);
	TCCR0 &=~  (1<<CS02);
	//SET WG00 = 0 AND WG01 = 0 FOR NORMAL MODE
	TCCR0 &=~ (1<<WGM01);
	TCCR0 &=~ (1<<WGM00);
	//ENABLE TIMER-0 OVER FLOW INTERRUPT FLAG
	TIMSK |=  (1<<TOIE0);
}
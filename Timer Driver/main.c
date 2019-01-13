/*
 * timer.c
 *
 * Created: 9/29/2017 2:19:08 PM
 * Author : Wesam
 */ 
#include "timer.h"
#include <util/delay.h>

volatile uint8_t x =0;
int main(void)
{
	timer_us(1000);
	_delay_us(1000000000);
	
	return 0;
}

ISR(TIMER0_OVF_vect)
{
	TCCR0 &=~   (1U<<CS00);
	TCCR0 &=~  (1U<<CS01);
	TCCR0 &=~   (1U<<CS02);
	TIMSK &=~ (1U<<TOIE0);
	x++;
}
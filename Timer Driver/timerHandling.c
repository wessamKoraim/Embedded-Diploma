/*
 * timerHandling.c
 *
 * Created: 9/29/2017 4:36:25 PM
 *  Author: Wesam
 */ 

 #include "timer.h"
 
 void timer_us(uint64_t inputDelay)
 {
	sei();
	//ENABLE TIMER-0 AND SET PRESCALAR = 1
	TCCR0 &=~   (1U<<CS00);
	TCCR0 &=~  (1U<<CS01);
	TCCR0 &=~  (1U<<CS02);
	//SET WGM00 = 0 AND WGM01 = 0 FOR NORMAL MODE
	TCCR0 &=~ (1U<<WGM01);
	TCCR0 &=~ (1U<<WGM00);
	//ENABLE TIMER-0 INTERRUPT
	TIMSK |=  (1U<<TOIE0);
		/************************************************************************/
		/*						PRESCALER = 1                                   */
		/************************************************************************/
		if ( inputDelay <= MAX_PRE_SCALER_1 )
			{
				
				TCNT0 =  256 - (inputDelay>>0);
				//ENABLE TIMER-0 AND SET PRESCALAR = 1
				TCCR0 |=   (1U<<CS00);
				TCCR0 &=~  (1U<<CS01);
				TCCR0 &=~  (1U<<CS02);
			}
		/************************************************************************/
		/*						PRESCALER = 8                                   */
		/************************************************************************/
		else if ( inputDelay <=  MAX_PRE_SCALER_8_4 )
			{
				TCNT0 =  256 + 21 - (inputDelay>>3);
				//ENABLE TIMER-0 AND SET PRESCALAR = 8
				TCCR0 &=~  (1U<<CS00);
				TCCR0 |=   (1U<<CS01);
				TCCR0 &=~  (1U<<CS02);
			}
		else if ( inputDelay <=  MAX_PRE_SCALER_8_3 )
			{
				TCNT0 =  256 + 24 - (inputDelay>>3);
				//ENABLE TIMER-0 AND SET PRESCALAR = 8
				TCCR0 &=~  (1U<<CS00);
				TCCR0 |=   (1U<<CS01);
				TCCR0 &=~  (1U<<CS02);
			}
		else if ( inputDelay <=  MAX_PRE_SCALER_8_2 )
			{
				TCNT0 =  256 - (inputDelay>>3);
				//ENABLE TIMER-0 AND SET PRESCALAR = 8
				TCCR0 &=~  (1U<<CS00);
				TCCR0 |=   (1U<<CS01);
				TCCR0 &=~  (1U<<CS02);
			}
		else if ( inputDelay <=  MAX_PRE_SCALER_8_1 )
		{
			TCNT0 =  256 + 28 - (inputDelay>>3);
			//ENABLE TIMER-0 AND SET PRESCALAR = 8
			TCCR0 &=~  (1U<<CS00);
			TCCR0 |=   (1U<<CS01);
			TCCR0 &=~  (1U<<CS02);
		}
		else if ( inputDelay <=  MAX_PRE_SCALER_8_0 )
		{
			TCNT0 =  256 + 30 - (inputDelay>>3);
			//ENABLE TIMER-0 AND SET PRESCALAR = 8
			TCCR0 &=~  (1U<<CS00);
			TCCR0 |=   (1U<<CS01);
			TCCR0 &=~  (1U<<CS02);
		}
	/************************************************************************/
	/*                        PRESCALER = 64                                */
	/************************************************************************/
		else if ( inputDelay <= MAX_PRE_SCALER_64_3 )
		{
			TCNT0 =  256 + 1 - (inputDelay>>6);
			//ENABLE TIMER-0 AND SET PRESCALAR = 64
			TCCR0 |=   (1<<CS00);
			TCCR0 |=   (1<<CS01);
			TCCR0 &=~  (1<<CS02);
		}
		else if ( inputDelay <= MAX_PRE_SCALER_64_2 )
		{
			TCNT0 =  256 + 2 - (inputDelay>>6);
			//ENABLE TIMER-0 AND SET PRESCALAR = 64
			TCCR0 |=   (1<<CS00);
			TCCR0 |=   (1<<CS01);
			TCCR0 &=~  (1<<CS02);
		}
		else if ( inputDelay <= MAX_PRE_SCALER_64_1 )
		{
			TCNT0 =  256 + 2 - (inputDelay>>6);
			//ENABLE TIMER-0 AND SET PRESCALAR = 64
			TCCR0 |=   (1<<CS00);
			TCCR0 |=   (1<<CS01);
			TCCR0 &=~  (1<<CS02);
		}
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	else if ( inputDelay <= MAX_PRE_SCALER_256 )
		{
			TCNT0 =  256 - (inputDelay>>8);
			//ENABLE TIMER-0 AND SET PRESCALAR = 256
			TCCR0 &=~  (1<<CS00);
			TCCR0 &=~  (1<<CS01);
			TCCR0 |=   (1<<CS02);
		}
	else if ( inputDelay <= MAX_PRE_SCALER_1024 )
		{
			TCNT0 =  256 - (inputDelay>>10);
			//ENABLE TIMER-0 AND SET PRESCALAR = 1024
			TCCR0 |=   (1U<<CS00);
			TCCR0 &=~  (1U<<CS01);
			TCCR0 |=   (1U<<CS02);
		}
 }


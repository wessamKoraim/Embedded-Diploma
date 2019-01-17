/*
 * UART.c
 *
 * Created: 3/2/2018 10:33:05 AM
 *  Author: MohamedMamdouh95
 */
#include "UART.h"

void UART_Init(void)
{
	UBRRL = 12;
	UCSRB |= ((1<<RXCIE)|(1<<RXEN)|(1<<TXEN));
	UCSRC |= ((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));
}
void UART_Write (uint8_t data)
{
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = data;
}

void UART_Read(char *Ptr)
{
	while((UCSRA & (1<<RXC))==0);
	*Ptr = UDR;
}

/*
ISR(USART_RXC_vect)
{
	uint8_t data_received;
	DDRA=0xff;
	PORTA=~PORTA;
	data_received=UDR;
	uart_write(13);
	//uart_write(data_received);
	uart_send_string("mamdouh");
	uart_write('\r');
}
*/


int x = 0;
switch(x)
{
	case 0:
	{
		/*send the char*/
		x = 1;
	}
	break;
	
	case 1:
	{}
	break;
	
	case 2:
	{}
	break;
}
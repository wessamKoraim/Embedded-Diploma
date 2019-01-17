/*
 * SPI.c
 *
 * Created: 3/2/2018 11:43:07 AM
 *  Author: Wesam
 */ 
 #include "SPI.h"

 void SPI_MasterInit(void)
 {
	/*set master mode*/
	/*set the leading edge falling and the trailing to be rising*/
	/*set sampling at the trailing edge*/
	SPCR |=		((1<<MSTR)|(1<<CPOL)|(1<<CPHA));
	/*set the SCK = F_CPU/64 */
	SPCR &=~	((1<<SPR1)|(1<<SPR0));
	SPSR |=		(1<<SPI2X);
	/*enable the SPI peripheral*/
	SPCR |=		(1<<SPE);
 }

void SPI_SlaveInit(void)
{
	DDRB &=~ ((1<<5)|(1<<7));
	DDRB |=  (1<<6);
	/*set slave mode*/
	SPCR &=~	(1<<MSTR);
	/*set the leading edge falling and the trailing to be rising*/
	/*set sampling at the trailing edge*/
	SPCR |=		((1<<CPOL)|(1<<CPHA));
	/*set the SCK = F_CPU/64 */
	SPCR &=~	((1<<SPR1)|(1<<SPR0));
	SPSR |=		(1<<SPI2X);
	/*enable the SPI peripheral*/
	SPCR |=		(1<<SPE);
}
 void SPI_Send(char Data)
 {
	SPDR = Data;
	while((SPSR & (1<<SPIF)) == 0);	
 }

 void SPI_Receive(char *Ptr)
 {
	/*read the status register then the data register to clear the SPIF flag*/
	while ((SPSR & (1<<SPIF)) == 0);
	*Ptr = SPDR;
 }







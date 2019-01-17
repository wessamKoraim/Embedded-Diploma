/*
 * GccApplication9.c
 *
 * Created: 3/2/2018 12:26:23 PM
 * Author : Wesam
 */ 

#include <avr/io.h>
#include "UART.h"
#include "SPI.h"

int main(void)
{
	UART_Init();
    SPI_SlaveInit();
	char SPI_DataRead;
    while (1) 
    {
		SPI_Receive(&SPI_DataRead);
		UART_Write(SPI_DataRead);
    }
}


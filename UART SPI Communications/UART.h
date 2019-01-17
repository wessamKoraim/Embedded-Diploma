/*
 * UART.h
 *
 * Created: 3/2/2018 10:32:51 AM
 *  Author: MohamedMamdouh95
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/interrupt.h>

#include <stdint.h>
#include <avr/io.h>
void UART_Write (uint8_t data);
void UART_Init(void);
void UART_Read(char *Ptr);

#endif /* UART_H_ */
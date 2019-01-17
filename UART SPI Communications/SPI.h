/*
 * SPI.h
 *
 * Created: 3/2/2018 11:43:26 AM
 *  Author: Wesam
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>
void SPI_MasterInit(void);
void SPI_Send(char Data);
void SPI_SlaveInit(void);
void SPI_Receive(char *Ptr);

#endif /* SPI_H_ */
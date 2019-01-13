/*
 * timer.h
 *
 * Created: 9/29/2017 2:22:29 PM
 *  Author: Wesam
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

void timer_us(uint64_t inputDelay);

#define MAX_PRE_SCALER_1	255

#define MAX_PRE_SCALER_8_4	400
#define MAX_PRE_SCALER_8_3	700
#define MAX_PRE_SCALER_8_2	1000
#define MAX_PRE_SCALER_8_1	1400
#define MAX_PRE_SCALER_8_0  2039

#define MAX_PRE_SCALER_64_3	3500
#define MAX_PRE_SCALER_64_2	7000
#define MAX_PRE_SCALER_64_1	9000
#define MAX_PRE_SCALER_64_0	16319

#define MAX_PRE_SCALER_256	65279
#define MAX_PRE_SCALER_1024	261119

#endif /* TIMER_H_ */
/*
 * lcdConfig.h
 *
 * Created: 9/17/2017 4:18:53 PM
 *  Author: Wesam
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



 #define D4					4
 #define D4_OUTPUT_DATA		PORTC
 #define D4_DIRECTION		DDRC

 #define D5					5
 #define D5_OUTPUT_DATA		PORTC
 #define D5_DIRECTION		DDRC

 #define D6					6
 #define D6_OUTPUT_DATA		PORTC
 #define D6_DIRECTION		DDRC

 #define D7					7
 #define D7_OUTPUT_DATA		PORTC
 #define D7_DIRECTION		DDRC
 
 #define EN					2
 #define EN_OUTPUT_DATA		PORTC
 #define EN_DIRECTION		DDRC

 #define RW					1
 #define RW_OUTPUT_DATA		PORTC
 #define RW_DIRECTION		DDRC

 #define RS					0
 #define RS_OUTPUT_DATA		PORTC
 #define RS_DIRECTION		DDRC			

#endif /* LCDCONFIG_H_ */
/*
 * numberToCharacter.c
 *
 * Created: 10/6/2017 8:15:36 PM
 *  Author: Wesam
 */ 

 #include "lcd.h"

 void vNumToChar(int num)
 {
	vGoto_XY(ELEMENT_1, LINE_2);
	int numCopy = num;
	uint_8_bits numOfDigits = 0;
	while (num!=0)
	{
		numOfDigits++;
		num /= 10;
	}
	while(numOfDigits != 0)
	{
		vGoto_XY(numOfDigits-1, LINE_2);
		vSendChar( (numCopy % 10) + 48 );
		numCopy /= 10;
		numOfDigits--;
	}
 }
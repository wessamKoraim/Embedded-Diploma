/*
 * calculator.c
 *
 * Created: 9/22/2017 8:22:02 PM
 *  Author: Wesam
 */ 

 #include "calculator.h"

 //'*' -> 0x2A
 //'+' -> 0x2B
 //'-' -> 0x2D
 //'/' -> 0x2F
 //'=' -> 0x3D

 uint_8_bits i = 0;
 uint_8_bits stringArray[7] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
 void vCharToString(uint_8_bits key)
 {
	stringArray[i] = key;
	i++;
 }

 int iPower(int number, uint_8_bits j)
 {
	if (j == 0)
	{
		return number;
	}
	else
	{
		while (j > 0)
		{
			number *= 10;
			j--;
		}
		return number;
	}
 }

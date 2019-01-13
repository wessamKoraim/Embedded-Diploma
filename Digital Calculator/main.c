/*
 * Calculator.c
 *
 * Created: 9/19/2017 12:06:35 AM
 * Author : Wesam
 */ 

#include "lcd.h"
#include "keypad.h"
#include "calculator.h"

uint_8_bits startMessage[] = "Welcome!";
uint_8_bits error[] = "ERROR";
extern uint_8_bits i;
extern uint_8_bits stringArray[7];
int main(void)
{
    volatile static uint_8_bits positionOfOperation = 0;
	volatile static uint_8_bits endOfInput = sizeof(stringArray) - 1;
	volatile static uint_8_bits firstIsNegative = 0, secondIsNegative = 0;
	volatile static uint_8_bits keyPressed = NO_VALID_INPUT;
	volatile static uint_8_bits j = 0;
	volatile static long int result = 0;
	volatile static long int generalVariable = 0;
	volatile static int num1 = 0, num2 = 0;
	
	vLcdInit();
	vKeypadInit();
	vSendString(startMessage, sizeof(startMessage)- (uint_8_bits) 1);
	while (1)
	{
		//SCAN FROM THE USER
		keyPressed = ucKeypadScan();
		
		if(keyPressed == 'C')
		{
			vClearLcd();
			i = 0;
			endOfInput = sizeof(stringArray) - 1;
			positionOfOperation = 0;
			firstIsNegative = 0;
			secondIsNegative = 0;
			keyPressed = NO_VALID_INPUT;
			j = 0;
			generalVariable = 0;
			result = 0;
			num1 = 0;
			num2 = 0;
			stringArray[0]= 0xFF;
			stringArray[1]= 0xFF;
			stringArray[2]= 0xFF;
			stringArray[3]= 0xFF;
			stringArray[4]= 0xFF;
			stringArray[5]= 0xFF;
			stringArray[6]= 0xFF;
			vSendString(startMessage, sizeof(startMessage)- (uint_8_bits) 1);
		}
		else
		{
			//THE USER ENTERED THE '=' SIGN TO FIND THE OUTPUT
			if (keyPressed == '=')
			{
				//FIND WHERE IS THE OPERATION IN THE STRING( +,-,*,/ )
				vGoto_XY(ELEMENT_1,LINE_2);
				while( (stringArray[positionOfOperation+1] != '+') && (stringArray[positionOfOperation+1] != '-') && (stringArray[positionOfOperation+1] != '*') && (stringArray[positionOfOperation+1] != '/') )
				{
					positionOfOperation++;
				}
				positionOfOperation++; /*because the searching started from element[1] in the array*/

				//FIND WHETHER THE 1ST INPUT NUMBER IS POSITIVE OR NEGATIVE AND RAISE THE NEGATIVE FLAG
				if (stringArray[0] == '-')
				{
					firstIsNegative = 1;
				}
				else; /*MISRA*/
				
				//START CONVERTING THE 1ST NUMBER FROM CHARACTER INTO AN INTEGER
				for (j = 0; j < positionOfOperation - firstIsNegative; j++)
				{
					num1 += iPower( (stringArray[positionOfOperation - 1 - j] - 48), j);
				}

				//FIND WHETHER THE 2ND INPUT NUMBER IS POSITIVE OR NEGATIVE AND RAISE THE NEGATIVE FLAG
				if ( stringArray[positionOfOperation+1] == '-' )
				{
					secondIsNegative = 1;
				}
				else; /*MISRA*/

				//START CONVERTING THE 2ND NUMBER FROM CHARACTER INTO AN INTEGER
				while( stringArray[endOfInput] == NO_VALID_INPUT )
				{
					endOfInput--;
				}
				for ( j = endOfInput; j > positionOfOperation + secondIsNegative; j--)
				{
					num2 += iPower( (stringArray[j] - 48), generalVariable);
					generalVariable++;
				}
				if ( stringArray[positionOfOperation] == '-' )
				{
					secondIsNegative = 1;
				} 
				else; /*MISRA*/
				//START DOING THE OPERATION TO THE TWO NUMBERS
				switch(stringArray[positionOfOperation])
				{
					case '+': 
						if ( (!firstIsNegative) && (!secondIsNegative) )
						{
							result = num1 + num2;
						} 
						else if(num1 > num2)
						{
							vSendChar('-');
							result = (long int) num1 - (long int) num2;
						}
						else if (num1 < num2)
						{
							vSendChar('-');
							result = (long int) num2 - (long int) num1;
						}
						else
						{
							vSendChar('0');
						}
						break;
					case '-':
						if (firstIsNegative && secondIsNegative)
						{
							result = num1 + num2;
							vSendChar('-');
						}
						else if(num1 > num2)
						{
							vSendChar('-');
							result = (long int) num1 - (long int) num2; 
						}
						else if (num1 < num2)
						{
							vSendChar('-');
							result = (long int) num2 - (long int) num1;
						}
						else
						{
							vSendChar('0');
						}
						break;
					case '*': result = (long int) num1 * (long int)num2; break;
					case '/': 
						//DIVISION BY ZERO CASE
						if (!num2)
						{
							vSendString(error, sizeof(error)-1);
						}
						else
						{
							result = (long int) num1 / (long int) num2;
						}
						break;
					default: break;
				}
				if ( 
					(!firstIsNegative && secondIsNegative) &&
					( (stringArray[positionOfOperation] == '*') || (stringArray[positionOfOperation] == '/') ) 
				   )
				{
					vSendChar(stringArray[positionOfOperation+1]);
				} 
				//TO PRINT NEGATIVE SIGN '-'
				else if (
				(firstIsNegative && !secondIsNegative) &&
				( (stringArray[positionOfOperation] == '*') || (stringArray[positionOfOperation] == '/') )
				)
				{
					vSendChar(stringArray[0]);
				}
				else;/*MISRA*/
				vNumToChar(result);
				//CONVERT THE OUTPUT INTO CHARACTERS TO BE DISPLAYED ON THE LCD
					/*
					//COUNT HOW MANY DIGITS IN THE RESULT
					
					while ( generalVariable )
					{
						generalVariable /= 10;
						j++;
					}

					//CONVERT INTEGER INTO STRING AND SEND IT TO THE LCD
					generalVariable = 0;
					while (  j!= 0 )
					{
						resultArray[generalVariable] = result % 10;
						result /= 10;
						j--;
						generalVariable++;
					}
					while(generalVariable != 0)
					{
						vSendChar(resultArray[generalVariable-1]+48);
						generalVariable--;
					}
					*/
			}
			//PUT WHAT THE USER ENTERS IN AN ARRAY
			else if (keyPressed != NO_VALID_INPUT)
			{
				if (!i)
				{
					vClearLcd();
					vSendChar(keyPressed);
					vCharToString(keyPressed);
				}
				else
				{
					vSendChar(keyPressed);
					vCharToString(keyPressed);
				}
			}
		}
	}

	return 0;
}


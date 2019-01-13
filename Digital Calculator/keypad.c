/*
 * keypad.c
 *
 * Created: 9/8/2017 11:14:51 AM
 *  Author: Ramy Elfouly
 */ 
 #include "keypad.h"
 #include <stdint.h>
 const static unsigned char g_keys[4][4]
 ={{'7','8','9','/'},
   {'4','5','6','*'},
   {'1','2','3','-'},
   {'C','0','=','+'}};

 void vKeypadInit(void)
 {
	#ifdef USE_ARM
	ROW0_DEN |=(1<<ROW0);
	#endif
	// set row as OUTPUTs
	ROW0_DIR |=(1<<ROW0);
	ROW1_DIR |=(1<<ROW1);
	ROW2_DIR |=(1<<ROW2);
	ROW3_DIR |=(1<<ROW3);
	//set lines as inputs
	LINE0_DIR &=~(1<<LINE0);
	LINE1_DIR &=~(1<<LINE1);
	LINE2_DIR &=~(1<<LINE2);
	LINE3_DIR &=~(1<<LINE3);
	//enable lines pull up
	LINE0_PULLUP |=(1<<LINE0);
	LINE1_PULLUP |=(1<<LINE1);
	LINE2_PULLUP |=(1<<LINE2);
	LINE3_PULLUP |=(1<<LINE3);
	//set ROWs initially to no output state
	ROW0_OUTPUTDATA |=(1<<ROW0);
	ROW1_OUTPUTDATA |=(1<<ROW1);
	ROW2_OUTPUTDATA |=(1<<ROW2);
	ROW3_OUTPUTDATA |=(1<<ROW3);

 }
 unsigned char ucKeypadScan(void)
 {
 uint8_t row,line = NO_VALID_INPUT,result = NO_VALID_INPUT;
 //loop on rows
 for (row=0;row<4;row++)
 {
	//set ROWs initially to no output state
	ROW0_OUTPUTDATA |=(1<<ROW0);
	ROW1_OUTPUTDATA |=(1<<ROW1);
	ROW2_OUTPUTDATA |=(1<<ROW2);
	ROW3_OUTPUTDATA |=(1<<ROW3);
	//set one row to output state
	switch(row)
	{
		case 0:ROW0_OUTPUTDATA &=~(1<<ROW0);break;
		case 1:ROW1_OUTPUTDATA &=~(1<<ROW1);break;
		case 2:ROW2_OUTPUTDATA &=~(1<<ROW2);break;
		case 3:ROW3_OUTPUTDATA &=~(1<<ROW3);break;
		default: /* MISRA */ break;
	}
	//check input
	if		((LINE0_DATAIN&(1<<LINE0))==0){line=0;}
	else if ((LINE1_DATAIN&(1<<LINE1))==0){line=1;}
	else if ((LINE2_DATAIN&(1<<LINE2))==0){line=2;}
	else if ((LINE3_DATAIN&(1<<LINE3))==0){line=3;}
	else {/* MISRA */}
	//if the input in the valid range
	if (line != NO_VALID_INPUT)
	{
		//wait till the input is gone
		while(ALL_LINES_CHECK == 0);
		//map the input to the global array
		result = g_keys[row][line];
		break;
	}
 }
 //return the mapped input
 return result;
}

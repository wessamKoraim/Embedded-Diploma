#include <stdio.h>

#define TOGGLE_BIT(Reg,PinNum) (Reg ^= (1<<PinNum)) 
 void bin(unsigned n);
 void decimalToBinary(char x);
 
 int main(void)
 {
	char x = 0xff;
	TOGGLE_BIT(x,1);
	bin(x);
	//decimalToBinary(6);
 }
 
 void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i>>1)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}

void decimalToBinary(char x)
{
	char i,bit;
	for(i = 7; i >= 0; i--)
	{
		bit = ((x>>i) & 0x1) ? 1 : 0;
		printf("%d",bit);
	}
}
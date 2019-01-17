#include <stdio.h>
#define ROTATE_LEFT(reg,num)  reg=((reg<<num)|(reg>>(sizeof(reg)<<3)-num))
#define ROTATE_RIGHT(reg,num) reg=((reg>>num)|(reg<<(sizeof(reg)<<3)-num))

void bin(unsigned int n,unsigned char size);

int main(void)
{
	unsigned int reg = 0xDEADBEEF;
	ROTATE_LEFT(reg,8);
	printf("%x\n",reg);
	ROTATE_RIGHT(reg,8);
	printf("%x\n",reg);
	return 0;
}

void bin(unsigned int n,unsigned char size)
{
    unsigned i;
    for (i = 1 << (size-1); i > 0; i = i>>1)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}
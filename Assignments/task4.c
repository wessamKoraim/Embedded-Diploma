#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int y = 0xCCBBFFAA;
	void *ptr = &y;
	printf("%x\n",*(unsigned char *)(ptr+0));
	printf("%x\n",*(unsigned char *)(ptr+1));
	printf("%x\n",*(unsigned char *)(ptr+2));
	printf("%x\n",*(unsigned char *)(ptr+3));


	return 0;
}
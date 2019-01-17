#include <stdio.h>
#include <stdlib.h>

int fun(int *ptr, int size);

int main(void)
{
	//int array[5] = {5,0,1,-3,6};
	int numberOfOnes, i, size;
	printf("please enter the size of array: "); 
	scanf("%d",&size);
	int array[size];
	for(i = 0; i < size; i++)
	{
		printf("enter element #%d: ",i); 
		scanf("%d",(array+i));
	}
	numberOfOnes = fun(array, size);
	for(i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		printf("%d\n",array[i]);
	}
	printf("return value = %d",numberOfOnes);
	return 0;
}

int fun(int *ptr, int size)
{
	int i, j, sum = 0;
	for(i = 1; i < size; i++)
	{
		for(j = i; j < size; j++)
		{
			if( *(ptr+j) > *(ptr+i-1) );
			else
			{
				*(ptr+i-1) = *(ptr+i-1) + *(ptr+j);
				*(ptr+j)   = *(ptr+i-1) - *(ptr+j);
				*(ptr+i-1) = *(ptr+i-1) - *(ptr+j);
			}
		}
	}
	
	
	for(i = 1; i < size; i++)
	{
		if(*(ptr+i) == *(ptr+i-1));
		else
		{
			sum += (*(ptr+i) - *(ptr+i-1) - 1);
		}
	}
	return sum;
}
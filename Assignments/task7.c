/*
Assignment 2 :

A binary gap within a positive integer N is any maximal sequence of consecutive
zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap
of length 2. The number 529 has binary representation 1000010001 and
contains two binary gaps: one of length 4 and one of length 3. The number
20 has binary representation 10100 and contains one binary gap of length 1.
The number 15 has binary representation 1111 and has no binary gaps.
Write a function:
int solution(int N)
that, given a positive integer N, returns the length of its longest binary gap. The
function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5,
because N has binary representation 10000010001 and so its longest
binary gap is of length 5. 
*/


#include <stdio.h>

int solution(int N);

int main(void)
{
	printf("%d",solution(0x80000001));
	return 0;
}

int solution(int N)
{
	char i=0,j=0,NumberOfZeros=0,compare=0;

	while((N&1)==0)
	{
		N = N >> 1;
		j++;
	}
	N = N >> 1;
	for(i=0; i <((sizeof(N))<<3)-j; i++)
	{
		if(((N&1)==0))
		{
			compare++;
		}
		else if(compare>NumberOfZeros)
		{
			
			NumberOfZeros = compare;
			compare = 0;
		}
		else
		{
			compare = 0;
		}
		N = N >> 1;
	}
	return NumberOfZeros;
}
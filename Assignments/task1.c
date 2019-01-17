#include <stdio.h>
#include <stdlib.h>

void function1(int x);
void fun2(int x);
void fun3(int x);

int main()
{
	void (*ptr[3])(int)={&function1,&fun2,&fun3};
	int x = 5;
	
	/* function1(10);
	fun2(20);
	fun3(30); */
	(*ptr[0])(x);
	return 0;
}

void function1(int x)
{
	printf("%s\n%d\n",__func__,x);
}

void fun2(int x)
{
	printf("%s\n%d\n",__func__,x);
}

void fun3(int x)
{
	printf("%s\n%d\n",__func__,x);
}
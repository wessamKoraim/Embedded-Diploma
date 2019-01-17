#include <stdio.h>
#include <stdlib.h>
//00000011_00101011 = 811
//00000010_10100101 = 677
void bin(unsigned n);
void genericSwap(void *firstPointer, void *secondPointer, int numberOfBytes);
int main()
{

    short firstAddress[] = {811,20,30};
    int secondAddress[] = {677,54,67};
    int numberOfBytes;
    printf("please enter number of bytes: "); scanf("%d",&numberOfBytes);
    void *firstPointer;
    firstPointer = firstAddress;
    void *secondPointer;
    secondPointer = secondAddress;
    genericSwap(firstAddress,secondAddress,numberOfBytes);
    return 0;
}
void genericSwap(void *firstPointer, void *secondPointer, int numberOfBytes)
{
    int i = 0;
    while(i<numberOfBytes)
    {
        printf("first byte before swap\n");
        bin(*((char*)firstPointer));
        printf("second byte before swap\n");
        bin(*((char*)secondPointer));
        *(char*) firstPointer = *(char*) firstPointer + *(char*) secondPointer;
        *(char*) secondPointer = *(char*) firstPointer - *(char*) secondPointer;
        *(char*) firstPointer = *(char*) firstPointer - *(char*) secondPointer;
        printf("first byte after swap\n");
        bin(*((char*)firstPointer));
        printf("second byte after swap\n");
        bin(*((char*)secondPointer));
        firstPointer++;
        secondPointer++;
        i++;
    }
}
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i>>1)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}


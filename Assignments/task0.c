#include <stdio.h>
#include <stdlib.h>

void Right_Angle_Triangle();
void Right_Angle_Triangle_Reversed();
void Triangle();
void Triangle_Reversed();
void Circle();
int main()
{
    int operation,end_program;
    while(1)
    {
        printf("\nchoose the operation needed:\n1-Right Angle Triangle\n2- Right Angle Triangle Reversed\n3-Triangle\n4-Reversed Triangle\n5-Rhombus\n\n");
        scanf("%d",&operation); printf("\n");
        if(operation == 1)
            Right_Angle_Triangle();
        else if(operation==2)
            Right_Angle_Triangle_Reversed();
        else if(operation==3)
            Triangle();
        else if(operation==4)
            Triangle_Reversed();
        else
            printf("invalid input");
        printf("\nif you want to exit enter 1, if not enter 0: "); scanf("%d",&end_program);
        if(end_program==1)
            break;
        else; //MISRA RULES
	//write a program that draws
	/*
                *
               * *
              *   *
             *     *
            *       *
             *     *
              *   *
               * *
                *
	*/
    }


    return 0;
}
void Right_Angle_Triangle()
{
    int width,i,j;
	printf("enter width: ");
	scanf("%d",&width);

    for( i=0;i<width+1;i++)
    {
        for(j=0; j<i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void Right_Angle_Triangle_Reversed()
{
    int width;
	printf("enter width: ");
	scanf("%d",&width);
    int i,j;
    for( i=0;i<width+1;i++)
    {
        for(j=width; j>0;j--)
        {
            if(j>i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}
void Triangle()
{
    int width,i,j,k;
    i=0;j=0;
    printf("enter width, hint: it is better to be an odd number: ");
    scanf("%d",&width);

    for(i=0;i<width;i=i+2)
    {
        k = (width-i-1)/2;
        for(j=0;j<width;j=j++)
        {
            if(j<k)
                printf(" ");
            else if(j>=k && j<width-k )
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
void Triangle_Reversed()
{
    int width,i,j,k;
    i=0;j=0;
    printf("enter width, hint: it is better to be an odd number: ");
    scanf("%d",&width);

    for(i=width;i>0;i=i-2)
    {
        k = (width-i)/2;
        for(j=width;j>0;j=j--)
        {
            if(j<k)
                printf(" ");
            else if(j>k && j<=width-k)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
/*
void Rhombus()
{
    int i,j,k,width;
    printf("please enter the width of the rhombus: ");
    scanf("%d",&width);
    k=(width-1)/2;
    for(i=0;i<2*width;i++)
    {
        for(j=0;j<2*width;j++)
        {
            if(i<=width)
            {
                if(j<k-i || j>k+i )
                    printf(" ");
                else if(j==k-i || j==k+i)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {

            }
        }
        printf("\n");
    }
}
*/

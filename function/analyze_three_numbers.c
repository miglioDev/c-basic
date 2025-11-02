/*
 * Program: Analyze Three Numbers
 * Description: Reads three integers and determines the maxi, min,
 * and average, also checks whether all numbers are even, odd or a mix of both.
 * Each operation is performed using a separate function cause i'm learning function :D
 */
#include <stdio.h>
int minimum(int a, int b,int c);
int maximum(int a, int b,int c);
float average(int a,int b,int c);
int even_odd(int a,int b,int c);
int main ()
{
    int a,b,c,max,min,type;
    float average_r;
    printf("Enter first number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);   
    printf("Enter third number:");
    scanf("%d",&c);

    max = maximum(a,b,c);
    min = minimum(a,b,c);
    average_r = average(a,b,c);
    type = even_odd(a,b,c);
    printf("Result:\n");
    printf("max=%d\tmin=%d\t",max,min);
    printf("average=%f\t",average_r);
    if (type == 0)
        printf("Type= all even\t");
        else if (type == 1)
        printf("Type= mix\t");
            else if (type == 2)
            printf("Type= all odd\t");
    return 0;
}
int maximum(int a, int b,int c)
{
    int max;
    max = a;
    if (a > max) max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int minimum(int a, int b,int c)
{
    int min;
    min = b;
    if (a < min) min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}
float average(int a,int b,int c)
{
    float avg;
    avg = (a+b+c)/3.00;
    return avg;
}
int even_odd(int a,int b,int c)
{
    int counter,output;
    counter = 0;
    if ( a%2 == 0) counter ++;
    if ( b%2 == 0) counter ++;
    if ( c%2 == 0) counter ++;
    if (counter == 0)
        {output = 2;}
        else if (counter == 1 || counter == 2)
            {output = 1;}
            else if (counter == 3)
                {output = 0;}
    return output;
}

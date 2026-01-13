// This program separates the integer and fractional parts of a floating-point number
// using a function with output parameters (pass-by-reference)

#include <stdio.h>

void sep(float x, int *a, float *b);

int main ()
{
    float x,b; 
    int a;

    printf("Enter a value: ");
    scanf("%f",&x);

    sep(x,&a,&b);

    printf("The whole part of the number: %d",a);
    printf("\nThe decimal part of the number: %f\n",b);

    return 0;
}

void sep(float x, int *a, float *b)
{
    *a = (int) x;

    *b =  x - (*a);
}
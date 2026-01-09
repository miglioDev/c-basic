// This program compares float, double, and long double precision by repeatedly halving a value until it reaches zero,
// counting how many iterations are needed for each floating-point type

#include <stdio.h>

int a_division(float x);
int b_division(double x);
int c_division(long double x);

int main ()
{
    int cycle;
    float x;

    printf("Enter a number: ");
    scanf("%f", &x);

    cycle = a_division(x);
    printf("\nFloat = %d",cycle);

    cycle = b_division(x);
    printf("\nDouble = %d",cycle);

    cycle = c_division(x);
    printf("\nLong double = %d",cycle);

    return 0;
}

int a_division(float x)
{
    int counter = 0;
    while(x != 0)
    {
        x = x/2;
        counter++;
    }

    return counter;
}

int b_division(double x)
{
    int counter = 0;
    while(x != 0)
    {
        x = x/2;
        counter++;
    }

    return counter;
}

int c_division(long double x)
{
    int counter = 0;
    while(x != 0)
    {
        x = x/2;
        counter++;
    }

    return counter;
}
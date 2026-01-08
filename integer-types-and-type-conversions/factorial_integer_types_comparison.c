// Computes the factorial of a given integer using short int, int, and long int
// to compare numeric limits - overflow behavior across different integer types

#include <stdio.h>

short int a_factorial(int x);
int b_factorial(int x);
long int c_factorial(int x);

int main ()
{
    int x;
    short int s_fatt;
    int i_fatt;
    long int l_fatt;

    printf("\nEnter a value: ");
    scanf("%d", &x);

    s_fatt = a_factorial(x);
    i_fatt = b_factorial(x);
    l_fatt = c_factorial(x);

    printf("\n=====================");
    printf("\nshort int = %d",s_fatt);
    printf("\nint = %d",i_fatt);
    printf("\nlong int = %ld",l_fatt);

    return 0;
}

short int a_factorial(int x)
{
    short int f = 1,i;
    for(i = 1; i <= x; i++)
    {
        f = f*i;
    }
    return f;
}

int b_factorial(int x)
{
    int f = 1,i;
    for(i = 1; i <= x; i++)
    {
        f = f*i;
    }
    return f;
}

long int c_factorial(int x)
{
    long int f = 1,i;
    for(i = 1; i <= x; i++)
    {
        f = f*i;
    }
    return f;
}
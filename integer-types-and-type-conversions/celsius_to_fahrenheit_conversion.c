// Converts a temperature from Celsius (integer input) to Fahrenheit (floating-point output),
// practicing function definition, return values, and basic type conversion in C

#include <stdio.h>

float f_conversion(int t);

int main ()
{
    int t;
    float f;
    printf("\nEnter temperature in C: ");
    scanf("%d",&t);

    f = f_conversion(t);
    printf("\nThats equal to %f",f);
}

float f_conversion(int t)
{
    float f;
    f = t *((float) 9/5) + 32;

    return f;
}
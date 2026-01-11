// Converts a temperature from Fahrenheit (integer input) to Celsius (floating-point output),

#include <stdio.h>

float conversion(int t);

int main ()
{
    int t;
    float f;
    printf("\nEnter temperature F: ");
    scanf("%d",&t);

    f = conversion(t);
    printf("\nThats C: %f\n",f);

    return 0;
}

float conversion(int t)
{
    float f;
    f = (t - 32) * ((float) 5/9);

    return f;
}
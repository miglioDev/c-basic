// Program that reads a floating-point value, prints it in scientific notation,
// converts it to an integer, and displays the integer in decimal, octal, and hexadecimal formats.

#include <stdio.h>

int main ()
{
    int a;
    float x;

    printf("Enter a floating point: ");
    scanf("%f",&x);

    a = (int) x;

    printf("\nScientific notation: %e",x);
    printf("\nConversion to integer: %d",a);
    printf("\nOctal notation: %#o",a);         //or use, (int) x  
    printf("\nExadecimal notation: %#x",a); 

    return 0;
}
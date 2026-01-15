// Program that calculates a house tax based on its value and zone,
// returning a floating-point tax amount or an error for unknown zones.

#include <stdio.h>

float tax(unsigned int x, char c);

int main ()
{
    unsigned int x;
    float taxed;
    char c;

    printf("Enter tha value: ");
    scanf("%u",&x);

    printf("Enter the zone (A, B, C, D): ");
    scanf(" %c",&c);

    taxed = tax(x,c);
    if(taxed == -1) {
        printf("Error -- zone code\n");
    }
        else {
    printf("\n%.2f taxes\n",taxed); }
    return 0;
}

float tax(unsigned int x, char c)
{
    float t;
    switch (c)
    {
        case 'A':
            t = (float) 5/1000*x;
        break;

        case 'B': 
            t = (float) 10/1000*x;
        break;

        case 'C':
            t = (float) 15/1000*x;
        break;

        case 'D':
            t = (float) 20/1000*x;
        break;

        default:
            t = -1;
        break;
    }
    return t;
}
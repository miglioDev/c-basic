/*
 * today's program reads two positive integers and calculates their
 * greatest common divisor (GCD) and least common multiple (LCM).
 * also determines whether the numbers are coprime, all of this with functions
 */
#include <stdio.h>
void welcome();
int read_pos_number();
int gcd(int x, int y);
int lcm(int x,int y,int GCD);
int coprime(int GCD);

int main ()
{
    int x,y,GCD,LCM,co__prime;
    welcome();
    x = read_pos_number();
    y = read_pos_number();
    GCD = gcd(x,y);
    LCM = lcm(x,y,GCD); 
    co__prime = coprime(GCD);
    printf("Result:\n");
    printf("GCD = %d\nLCM = %d\n",GCD,LCM);
    if (co__prime)
        printf("Number are coprime\n");
        else 
            printf("Number are not coprime\n");
    return 0;
}

void welcome()
{
    printf("== Number Relationship Analyzer ==\n");
}
int read_pos_number()
{
    int a;
    a = -1;
    do
    {
        printf("Enter positive integer:");
        scanf("%d",&a);
        printf("\n");
    }
    while (a <= 0);
    return a;
}
int gcd(int x, int y)
{
    int gcd;
    do
    {
        if ( x > y)
        {
            x = x-y;
        }
            else if (x < y)
            {
                y = y-x;
            }
    }
    while ( x != y);
    gcd = x;
    return gcd;
}
int lcm(int x,int y,int GCD)
{
    int output;
    output = (x*y)/GCD;
    return output;
}
int coprime(int GCD)
{
    int co_prime;
    if (GCD == 1)
    {
        co_prime = 1; 
    }
        else
            co_prime = 0;
    return co_prime;
}
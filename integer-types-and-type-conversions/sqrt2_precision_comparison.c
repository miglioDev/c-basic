// Computes sqrt(2)*10000 using float, double, and long double to compare precision limits.

#include <stdio.h>
#include <math.h>

float f_squareroot();
double d_squareroot();
long double Lf_sqaureroot();

int main ()
{
    float x;
    double y;
    long double z;

    x = f_squareroot();
    y = d_squareroot();
    z = Lf_sqaureroot();

    printf("===================\n");
    printf("\nfloat = %.50f", x);
    printf("\ndouble = %.50f", y);
    printf("\nlong double = %.50Lf", z);
}

float f_squareroot()
{
    float x;

    x = sqrtf(2.0f)*10000;

    return x;
}

double d_squareroot()
{
    double y;

    y = sqrt(2.0)*10000;

    return y;
}

long double Lf_sqaureroot()
{
    long double y;

    y = sqrtl(2.0L)*10000;

    return y;
}
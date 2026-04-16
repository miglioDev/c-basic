// compute factorial of a integer using recursion
#include <stdio.h>
#include <stdlib.h>

int recursive_factorial(int n);

int main ()
{
    int res,x = 0;

    printf("Enter value: ");
    scanf("%d",&x);

    res = recursive_factorial(x);

    printf("Factorial = %d",res);

    return 0;
}

int recursive_factorial(int n)
{
    if(n == 0) {
        return 1; }

    else 
        return n*(recursive_factorial(n-1));
}
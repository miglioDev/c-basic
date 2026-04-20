// Recursive implementation of Fibonacci sequence O(2^n) 
#include <stdio.h>

int fib(int n);

int main ()
{
    int n,result;

    printf("== Fibonacci recursive ==\n");
    printf("Enter a number: ");
    scanf("%d",&n);

    result = fib(n);

    printf("\nResult = %d",result);

    return 0;
}

int fib(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    else 
        return (fib(n-1) + fib(n-2));
}
// Tail-recursive factorial using accumulator pointer
#include <stdio.h>

int fact_tail(int x, int *acc);

int main ()
{
    int x,res;
    res = 1;

    printf("Enter number: ");
    scanf("%d",&x);

    res = fact_tail(x,&res);

    printf("\nResult = %d",res);

    return 0;
}

int fact_tail(int x, int *acc)
{
    if(x == 0) {
    return *acc; }
        else {
            *acc = (*acc) * x;
            return fact_tail(x-1,acc); }
}
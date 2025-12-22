// Program that reads an array using pointer arithmetic 
// and checks whether its elements are in strictly increasing order

#include <stdio.h>
#define dim 8

void load(int *v);
int is_increasing(int *v);

int main ()
{
    int is_incr;
    int v[dim];

    load(&v[0]);
    is_incr = is_increasing(&v[0]);

    if(is_incr) printf("\nThe fun. is increasing!\n");
        else
        printf("\n-- The arr is not increasing --\n");

    return 0;
}

void load(int *v)
{
    int i;

    for(i = 0; i < dim; i++)
    {
        printf("\nEnter number the %dth value: ",i);
        scanf("%d",v+i);
    }
}

int is_increasing(int *v)
{
    int increasing = 1,i;
    for(i = 1; i < dim; i++)
    {
        if((*(v+i)) < *(v+(i-1))) increasing = 0;
    }

    return increasing;
}
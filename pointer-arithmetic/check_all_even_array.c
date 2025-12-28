// Loads an integer array using pointer arithmetic, checks i all elements are even,
// then prints the array with result practicing vectors, functions, and pointers

#include <stdio.h>
#define dim 6

void load(int v[dim]);
int all_even(int v[dim]);
void visualize(int v[dim]);
void result(int c);

int main ()
{
    int c,v[dim];

    load(v);
    c = all_even(v);
    visualize(v);
    result(c);

    return 0;
}

void load(int v[dim])
{
    int i;

    printf("\n== Welcome enter and array ==\n");

    for(i = 0; i < dim; i++)
    {
    printf("\nEnter number for address %d) : ",i);
    scanf("%d", (v+i));
    }
}

int all_even(int v[dim])
{
    int i,cond = 1;

    for(i = 0; i < dim; i++)
    {
        if(*(v+i)%2 != 0) cond = 0;
    }

    return cond;
}

void visualize(int v[dim])
{
    int i;

    printf("Address: ");
    for(i = 0; i < dim; i++)
    {
        printf("\t%d",i);
    }
    printf("\n");

    printf("value:\t");
    for(i = 0; i < dim; i++)
    {
        printf("\t%d", *(v+i));
    }
    printf("\n");
}

void result(int c)
{
    if(c) printf("All the number in the array are even\n");
    else 
        printf("Ther's one or more number not even in the array\n");
}
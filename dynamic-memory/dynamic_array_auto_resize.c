// Implements a dynamic integer array that automatically grows when full
// the program starts with a small capacity 2 and doubles the allocated memory when needed
// using realloc, stops when the user enters -1
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,x = 0,size = 0,capacity = 2;
    int *v = malloc(2 * sizeof(int));
    if(v == NULL) {
        printf("Memory fail: ");
        exit(EXIT_FAILURE); }

    while(x != -1)
    {
        printf("\nEnter a number: ");
        scanf("%d",&x);

        if(size == capacity) {
            v = realloc(v, capacity * 2 * sizeof(int));
            capacity = capacity*2;
        }

        v[size] = x;
        size++;
    }

    printf("\n== Array ==");
    for(i = 0; v[i] != -1; i++)
    {
        printf("\nIndex: %d\tValue: %d",i,v[i]);
    }

    free(v);
    v = NULL;

    return 0;
}
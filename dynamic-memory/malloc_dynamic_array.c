// Dynamically allocates an array of 5 integers using malloc, initializes
// the elements through pointer arithmetic, prints them, and frees the memory.
// Practice: basic dynamic arrays and pointer arithmetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *x = NULL;

    x = malloc(5 * sizeof(int));

    if(x == NULL) {
        printf("Error: memory");
        return 1; }

    for(i = 0; i < 5; i++)
    {
        *(x+i) = i;
    }

    for(i = 0; i < 5; i++)
    {
        printf("x = %d\n", x[i]);
    }

    free(x);
    x = NULL;

    return 0;
}
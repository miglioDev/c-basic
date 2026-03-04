// Allocates an integer dynamically using malloc, assigns a value then prints it,
// the goal is to properly frees the allocated memory. Basic heap allocation and error handling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = NULL;
    
    x = malloc(sizeof(int));

    if( x == NULL ) {
        printf("Error: memory\n");
        exit(1); }

    *x = 42;
    printf("x = %d\n", *x);
    free(x);
    x = NULL;

    return 0;
}
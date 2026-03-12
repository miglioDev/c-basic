// Allocates an integer array using calloc, to initializes all elements to zero
// then prints the default values to demonstrate automatic initialization
// Practice: calloc usage and zero-initialized dynamic memory
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n,i;
    int *x;

    printf("Enter dimension of the array: ");
    scanf("%d", &n);

    x = calloc(n, sizeof(int));
    if(x == NULL) {
        printf("Error memory fail\n");
        exit(EXIT_FAILURE); }

    for(i = 0; i < n; i++)
    {
        printf("Index: %d\tValue: %d\n",i,x[i]);
    }

    free(x);
    x = NULL;

    return 0;
}
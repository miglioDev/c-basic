// Dynamically allocates an integer array based on user input,
// reads values into the array, prints them, and frees the memory

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;
    int *n = NULL;

    printf("How many numbers will you enter:\n");
    scanf("%d",&x);

    n = malloc(x * sizeof(int));
    if(n == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE); }

    for(i = 0; i < x; i++)
    {
        printf("\nEnter number %d: ",i);
        scanf("%d",&n[i]);
    }

    printf("\nArray: ");
    for(i = 0; i < x; i++)
    {
        printf("\t%d",n[i]);
    }

    free(n);
    n = NULL;

    return 0;
}
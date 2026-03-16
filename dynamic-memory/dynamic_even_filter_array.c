// Reads an array of integers from the user and dynamically builds a second
// array containing only the even numbers, the second array grows using realloc
// as new even values are found
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,even_count = 0,n;
    int *array = NULL;
    int *array_even = NULL;

    printf("How many number? ");
    scanf("%d",&n);

    array = malloc(n * sizeof(int));
    if(array == NULL) {
        printf("\nError: memory fail");
        exit(EXIT_FAILURE); }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter number index %d : ",i);
        scanf("%d", &array[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(array[i]%2 == 0) {
                array_even = realloc(array_even, (even_count + 1) * sizeof(int));
                array_even[even_count] = array[i];
                even_count++; 
        }
    }

    for(i = 0; i < even_count; i++)
    {
        printf("Index: %d\tValue: %d\n",i,array_even[i]);
    }

    free(array);
    free(array_even);

    return 0;
}
// Allocates a dynamic integer array using malloc, fills it with user input,
// expands the array using realloc then prints all elements and frees memory
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n,m,i;
    int *x = NULL;
    int *new_array = NULL;

    printf("Enter the desired dimension of the array: ");
    scanf("%d", &n);

    x = malloc(n * sizeof(int));
    if(x == NULL) {
        printf("Error: memory fail\n");
        exit(EXIT_FAILURE); }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter value at index %d: ",i);
        scanf("%d",&x[i]);
    }

    printf("\n\nNow increase the dimension: ");
    scanf("%d", &m);

    new_array = realloc(x, (n+m) * sizeof(int));
    if(new_array == NULL) {
        printf("Error memory leak\n");
        free(x);
        exit(EXIT_FAILURE); }

    for(; i < (m+n); i++)
    {
        printf("\nEnter value at index %d: ",i);
        scanf("%d",&new_array[i]);
    }

    printf("\n== Array ==");
    for(i = 0; i < (m+n); i++)
    {
        printf("\nIndex:%d\tValue:%d",i,new_array[i]);
    }

    free(new_array);
    new_array = NULL;

    return 0;
}
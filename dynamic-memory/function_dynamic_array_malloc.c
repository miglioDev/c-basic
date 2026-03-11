// Write a function that dynamically allocates an integer array of a given size
// using malloc, The main program fills the array with user input, prints the values

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n);

int main()
{
    int n,i;
    int *v; //array

    printf("How many number will you enter?: ");
    scanf("%d",&n);

    v = create_array(n);

    for(i = 0; i < n; i++)
    {
        printf("\nIndex %d: ",i);
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("Index: %d\tValue: %d\n",i,v[i]);
    }

    free(v);
    v = NULL;

    return 0;
}

int *create_array(int n)
{
    return (int *) malloc(n * sizeof(int));
}
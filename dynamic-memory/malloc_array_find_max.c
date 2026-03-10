// Dynamically allocates an integer array based on user input,
// reads the values, finds the maximum element, and frees the memory
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i,max;
    int *n = NULL;

    printf("How many number will you enter? ");
    scanf("%d",&x);

    n = malloc(x * sizeof(int));
    if(n == NULL) {
        printf("Error: memory issue\n");
        return 1; }

    for(i = 0; i < x; i++)
    {
        printf("Enter number at index %d: ",i);
        scanf("%d",&n[i]);
    }

    max = n[0];
    for(i = 1; i < x; i++)
    {
        if(n[i] > max) {
            max = n[i]; }
    }

    free(n);
    n = NULL;
    printf("Max = %d\n",max);
    
    return 0;
}
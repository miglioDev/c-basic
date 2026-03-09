// Dynamically allocates an integer array based on user input,
// and computes the sum, then frees the allocated memory
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x,sum = 0;
    int *n = NULL;

    printf("\nHow many number do want to enter? ");
    scanf("%d",&x);

    n = malloc(x * sizeof(int));

    if(n == NULL) {
        printf("Memory allocation failed\n");
        exit(1); }

    for(i = 0; i < x; i++)
    {
        printf("\nEnter number at index %d: ",i);
        scanf("%d",&n[i]);

        sum = sum + n[i];
    }

    free(n);
    n = NULL;
    printf("\nThe sum is %d",sum);

    return 0;
}
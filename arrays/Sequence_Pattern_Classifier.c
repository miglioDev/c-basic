// This is a Sequence Pattern Classifier
// Reads 10 integers into a vector and determines whether the sequence is
// strictly increasing, strictly decreasing, constant, or mixed.
// Im learning algorithmic classification using array traversal and
// comparison logic in C.
#include <stdio.h>
#define dim 10

int pattern(int arr[]);

int main ()
{
    int arr[dim] = {};
    int i,result;

    printf("Welcome! (enter 10 number)");
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }

    result = pattern(arr);
        if (result == 0)
        printf("The numbers are mixed\n");
            if (result == 1)
            printf("The numbers are increasing\n");
                if (result == 2)
                printf("The numbers are decreasing\n");
                    if (result == 3)
                    printf("The numbers are all equal\n");

    return 0;
}

int pattern(int arr[])
{
   int i,inc = 1, dec = 1, equal = 1;

   for (i = 0; i < dim - 1; i++)
   {
    if(arr[i] < arr[i+1]) inc = 0;
    if(arr[i] > arr[i+1]) dec = 0;
    if(arr[i] != arr[i+1]) equal = 0;
   }
    if (equal == 1) return 3;
    if (inc == 1)   return 1;
    if (dec == 1)   return 2;
return 0;
}
// program that fills an array using pointer arithmetic 
// then checks whether all elements have the same value; practice with arrays and pointers


#include <stdio.h>
#define dim 8

void load(int *arr);
int all_equal(int *arr);

int main ()
{
    int is_equal;
    int arr[dim];

    load(arr);
    is_equal = all_equal(arr);

    if(is_equal) printf("All the values are equal!\n");
    else 
        printf("The values in the array are not equal\n");

    return 0;
}

void load(int *arr)
{
    int i;
    for(i = 0; i < dim; i++)
    {
    printf("Enter number %d: ",i);
    scanf("%d",arr+i);
    }
}

int all_equal(int *arr)
{
    int i,j,equal = 1;

    for(i = 0; i < dim-1; i++)
    {
        for(j = 0; j < dim-1;j++)
        {
            if(*(arr+i) != *(arr+j)) equal = 0;
        }
    }

    return equal; 
}
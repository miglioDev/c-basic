//This program is a basic Selection Sort algoritm with array
#include <stdio.h>
#define dim 10
void array_sorter(int arr[]);

int main ()
{
    int arr[dim] = {};
    int i;

    printf("== Welcome! i will ask for 10 integer ==\n");
    for (i = 0; i < dim ; i++)
    {
        printf("Number:\n");
        scanf("%d",&arr[i]);
    }
    printf("Before sorting\n");
        for (i = 0; i < dim; i++) {
        printf("value= %d\taddress= %d\n",arr[i],i);
    }

    array_sorter(arr);

    printf("After sorting\n");
    for (i = 0; i < dim; i++) {
        printf("value= %d\tnew address= %d\n",arr[i],i);
    }

    return 0;
}

void array_sorter(int arr[])
{
    int i,k,j;
    for (i = 0; i < dim ; i++)
    {
        for(j = i; j < dim ; j++) 
        {
            if (arr[i] > arr[j]) {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;}
        }
    }
}
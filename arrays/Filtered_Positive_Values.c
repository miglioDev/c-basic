// This program reads an array of integers and builds a new array containing
// only the strictly positive values, and print address + value 

#include <stdio.h>
#define dim 100

int positive(int arr[], int abs[],int n);

int main ()
{
    int arr[dim] = {};
    int abs[dim] = {};

    int n = -1,i,pos;

    do
    {
    printf("How many number will you enter?\n");
    scanf("%d",&n);
    }
    while (n <= 0 || n > 100);

    for (i = 0; i < n ; i++ )
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }

    pos = positive(arr,abs,n);

    printf("There are %d positive numbers\n",pos);
    for (i = 0; i < n ; i++)
    {
        if(abs[i] > 0) {
            printf("%d\taddress: %d\n",abs[i],i); }
    }

    return 0;
}

int positive(int arr[], int abs[],int n)
{
    int counter = 0,i;

    for (i = 0; i < n; i++)
    {
        if(arr[i] > 0) {
        abs[i] = arr[i];
        counter ++;}
    }
    return counter;
}
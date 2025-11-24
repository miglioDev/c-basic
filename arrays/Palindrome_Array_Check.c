// This program loads an array from user input and checks whether it is
// palindromic, comparing symmetric elements from both ends of the array.

#include<stdio.h>
#define dim 5

void load_arr(int arr[]);
int check(int arr[]);

int main () 
{
    int result;
    int arr[dim];

    load_arr(arr);
    result = check(arr);

    if (result) {
        printf("The arr is palindromic\n"); }
        else {
            printf("The arr is not palindromic\n"); }


    return 0;
}

void load_arr(int arr[])
{
    printf("== Welcome ==");
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }
}

int check(int arr[])
{
    int pl = 1;
    int i,j = dim-1;
    for (i = 0; i < dim; i++)
    {
        if (arr[i] != arr[j]) {
            pl = 0; } 
        j--;
    }

    return pl;
}
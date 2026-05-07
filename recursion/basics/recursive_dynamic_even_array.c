// recursively build a dynamic array containing only even values from another array
#include <stdio.h>
#include <stdlib.h>

void build_even_array(int a[], int n,int **even_arr, int *even_count);
void print_arr(int a[], int n);

int main ()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 0,even_count = 0;
    int *even_arr = NULL;

    build_even_array(a,n,&even_arr,&even_count);
    print_arr(even_arr,even_count);

    return 0;
}

void build_even_array(int a[], int n,int **even_arr, int *even_count)
{
    if(n > 9) return;

    if(a[n]%2 == 0) {
        (*even_count)++;

        *even_arr = (int *)realloc(*even_arr,(*even_count) * sizeof(int));
        (*even_arr)[(*even_count)-1] = a[n];

        build_even_array(a,n+1,even_arr,even_count); }
    else
        build_even_array(a,n+1,even_arr,even_count);
}

void print_arr(int a[], int n)
{
    printf("\nArray: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
}
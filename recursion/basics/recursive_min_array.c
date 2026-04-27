// Recursive function to find the minimum element in an array 
// (by comparing each element with the minimum of the previous subarray) problem reduction
#include <stdio.h>
#define DIM 6

void load_arr(int a[DIM]);
void print_arr(int a[DIM]);
int min(int a, int b);
int recursive_min(int a[], int n);

int main ()
{
    int m,arr[DIM];

    load_arr(arr);
    print_arr(arr);
    m = recursive_min(arr,DIM);
    printf("\nMin: %d",m); 

    return 0;
}

void load_arr(int a[DIM])
{
    for(int i = 0; i < DIM; i++)
    {
        printf("\nEnter value index %d: ",i);
        scanf("%d",&a[i]);
    }
}

void print_arr(int a[DIM])
{
    printf("\nArray:\n");
    for(int i = 0; i < DIM; i++)
    {
        printf("%d\t",a[i]);
    }
}

int min(int a, int b)
{
    if(a > b) 
        return b;
    
    else return a;
}

int recursive_min(int a[], int n)
{
    if(n == 0) return a[0];

    else {
        return min(a[n],recursive_min(a,n-1));
    }
}
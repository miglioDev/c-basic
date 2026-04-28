// Recursive search in array: scans from the end (n) to 0, returning the index of x if found, otherwise -1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 16

void load_print_array(int a[DIM]);
int find_x(int a[], int n, int x);

int main ()
{
    int x,n,arr[DIM];
    srand(time(NULL));

    load_print_array(arr);

    printf("\nEnter number to find: ");
    scanf("%d",&x);

    n = DIM-1;
    n = find_x(arr,n,x);
    if(n < 0) {
    printf("\nValue not found\n"); }
        else 
        printf("Value found index: %d",n);

    return 0;
}

void load_print_array(int a[DIM])
{
    printf("Array:\n");
    for(int i = 0; i < DIM; i++)
    {
        a[i] = rand()%10;
        printf("%d\t",a[i]);
    }
}

int find_x(int a[], int n, int x)
{
    if(n < 0)
        return -1;

    if(x == a[n])
        return n;

    return find_x(a,n-1,x);
}
// Quick Sort algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100

void load_vector(int arr[]);
void Swap(int i, int j, int arr[]);
int partition(int a[], int p, int r);
void QuickSort(int a[], int p, int r);

int main ()
{
    srand(time(NULL));
    int p,r,arr[DIM];
    p = 0;
    r = DIM-1;

    printf("Array: \n");
    load_vector(arr);

    QuickSort(arr,p,r);
    printf("\nSorted Array: \n");

    for(int i = 0; i < DIM; i++)
    {
        printf("%d  ",arr[i]);
    }

    return 0;
}

void load_vector(int arr[])
{
    for(int i = 0; i < DIM; i++)
    {   
        arr[i] = rand()%100;
        printf("%d  ",arr[i]);
    }
}

void Swap(int i, int j, int arr[])
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int a[], int p, int r)
{
    int pivot, pivot_pos, i;

    Swap(p, (p+r)/2, a);

    pivot = a[p];
    pivot_pos = p;

    for(i = p+1; i <= r; i++)
    {
        if(a[i] < pivot) {
            pivot_pos++;
            Swap(pivot_pos,i,a); }
    }

    Swap(p,pivot_pos,a);

    return pivot_pos;
}

void QuickSort(int a[], int p, int r)
{
    int q;

    if(p < r) {

        q = partition(a,p,r);

        QuickSort(a,p,q-1);

        QuickSort(a,q+1,r);
    }
}
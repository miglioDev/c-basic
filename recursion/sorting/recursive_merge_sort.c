// Implement recursive Merge Sort 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 30

void load_arr(int a[], int n);
void print_arr(int a[], int n);
void MergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

int main ()
{
    srand(time(NULL));
    int a[DIM];
    int n = DIM;

    load_arr(a,n);
    printf("\nArray:\n");
    n = 0;
    print_arr(a,n);

    MergeSort(a,0,DIM-1);
    printf("\nArray After Merge Sort:\n");
    print_arr(a,n);

    return 0;
}

void load_arr(int a[], int n)
{
    if(n < 0) return;
    else {
        a[n] = rand()%100;
        load_arr(a,n-1); }
}

void print_arr(int a[], int n)
{
    if(n >= DIM) return;
    else {
        printf("%d  ",a[n]);
        print_arr(a,n+1); }
}

void MergeSort(int arr[], int p, int r)
{
    int q;

    if(p < r) {

        q = (p+r)/2;

        MergeSort(arr,p,q); 
        MergeSort(arr,q+1,r); 

        merge(arr,p,q,r);
    }
}

void merge(int arr[], int p, int q, int r)
{
    int *v;
    int i,j,k;

    i = p;
    j = q+1;
    k = p;

    v = malloc(sizeof(int) * (r + 1));

    while((i <= q) && (j <= r))
    {
        if(arr[i] <= arr[j])
        v[k++] = arr[i++];
            else
            v[k++] = arr[j++];
    }

    while(i <= q)
    {
        v[k++] = arr[i++];
    }

    while(j <= r)
    {
        v[k++] = arr[j++];
    }

    for(k = p; k <= r; k++)
    {
        arr[k] = v[k];
    }

    free(v);
}



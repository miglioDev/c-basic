// Implement Merge Sort using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void load_array(int arr[], int k);
void print_array(int arr[], int k);
void MergeSort(int arr[], int p, int r);
void Merge(int arr[], int p, int q, int r);

int main ()
{
    int k;
    srand(time(NULL));

    printf("Enter the array dimension: ");
    scanf("%d",&k);

    int *arr = (int *) calloc(k,sizeof(int));
    if(arr == NULL) {
        printf("Error: memory allocation failed\n");
        exit(EXIT_FAILURE); }

    load_array(arr,k);
    print_array(arr,k);

    printf("\n\nAfter Merge Sort:\n");
    MergeSort(arr,0,k-1);
    print_array(arr,k);

    free(arr);
}

void load_array(int arr[], int k)
{
    for(int i = 0; i < k; i++)
    {
        arr[i] = rand()%100;
    }
}

void print_array(int arr[], int k)
{
    for(int i = 0; i < k; i++)
    {
        printf("%d  ",arr[i]);
    }
}

void MergeSort(int arr[], int p, int r)
{
    int q;

    if(p < r) {
        
        q = (p + r) / 2;

        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);

        Merge(arr,p,q,r);
    }
}

void Merge(int arr[], int p, int q, int r)
{
    int i,j,k; 
    int *B = malloc((r+1) * sizeof(int));

    i = p;
    j = q + 1;
    k = p;

    while(i <= q && j <= r)
    {
        if(arr[i] < arr[j]) {
            B[k++] = arr[i++]; }
        else {
            B[k++] = arr[j++];
        }
    }

    while(i <= q)
    {
        B[k++] = arr[i++];
    }

    while(j <= r)
    {
        B[k++] = arr[j++];
    }

    for(k = p; k <= r; k++)
    {
        arr[k] = B[k];
    }

    free(B);
}
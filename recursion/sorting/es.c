#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void load_arry(int arr[], int k);
void print_array(int arr[], int k);

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

    load_arry(arr,k);
    print_array(arr,k);
}

void load_arry(int arr[], int k)
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

void sorting_fun()
{
    //work in progress
}
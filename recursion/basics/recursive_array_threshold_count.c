// Recursively traverse an array to count and print values greater than a threshold
#include <stdio.h>
#define DIM 10

void recursive_count(int a[], int n, int x, int *counter);
void print(int a[], int n);

int main ()
{
    int x,n = 0,c = 0,a[DIM] = {2, 4, 5, 6, 7, 8, 9, 12, 15, 17};

    printf("\nPick a filter value: ");
    scanf("%d",&x);

    recursive_count(a,n,x,&c);

    n = 0;
    printf("\nArray:\n");
    print(a, n);
    printf("\nThere are %d values greater then %d\n",c,x);

    return 0;
}

void recursive_count(int a[], int n, int x, int *counter)
{
    if(n >= DIM-1) return;
    if(a[n] >= x) 
            (*counter)++;

    recursive_count(a,n+1,x,counter);
}

void print(int a[], int n)
{
    if(n >= DIM-1) return;
    else {
        printf("%d\t",a[n]);
        print(a,n+1); }
}

// this program reads two arrays of equal size from the user and merges them
// into a third array whose size is twice as large
// then displays the merged array
#include <stdio.h>
#define dim 5

void enter_vec_fun(int v1[]);
void enter_vec_fun(int v2[]);
void copy_fun(int v1[], int v2[], int v3[]);
void print_vector(int v3[]);

int main ()
{
    int v1[dim];
    int v2[dim];
    int v3[10];

    enter_vec_fun(v1);
    enter_vec_fun(v2);

    copy_fun(v1,v2,v3);

    print_vector(v3);

    return 0;
}

void enter_vec_fun(int v1[])
{
    int i;
    printf("Enter 5 number:\n");
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&v1[i]);
    }
}

void copy_fun(int v1[], int v2[], int v3[])
{
    int i,j = 5;
    for (i = 0; i < dim; i++)
    {
        v3[i] = v1[i];
    }
    for (i = 0; i < dim; i++)
    {
        v3[j] = v2[i];
        j++;
    }
}

void print_vector(int v3[])
{
    int i;

    printf("\nIndex:\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t",i);
    }

    printf("\nValues:\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t",v3[i]);
    }
}
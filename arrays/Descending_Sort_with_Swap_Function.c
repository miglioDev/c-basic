// this program reads an array from the user, displays its contents,
// sorts the values in descending order by repeatedly swapping elements
// through a dedicated swap function

#include <stdio.h>
#define dim 8

void load_v(int v[]);
void visual_v(int v[]);
int order_v(int v[]);
void int_swap(int *p1, int *p2);

int main ()
{
    int v[dim];
    int n_of_swap;

    load_v(v);
    visual_v(v);
    n_of_swap = order_v(v);

    printf("\n== After swap ==\n");
    visual_v(v);
    printf("Number of swap: %d\n",n_of_swap);

    return 0;
}


void load_v(int v[])
{
    printf("== Welcome enter 8 value ==\n");
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&v[i]);
    }
}

void visual_v(int v[])
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("index:%d\t",i);
        printf("value:%d\n",v[i]);
    }
}

int order_v(int v[])
{
    int i,j,swap = 0;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            if (v[i] > v[j])
            {
                int_swap(&v[i], &v[j]);

                swap ++;
            }
        }
    }
    return swap;
}

void int_swap(int *p1, int *p2)
{
    int k; 
    k = *p1;
    *p1 = *p2;
    *p2 = k;
}
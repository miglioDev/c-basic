// This program loads an array of fixed size and checks whether its values
// first increase up to a peak and then decrease until the end
#include <stdio.h>
#define dim 8

int hill_pattern(int v[]);
void load_v(int v[]);

int main ()
{
    int v[dim];
    int type = 0;

    load_v(v);
    type = hill_pattern(v);

    if (type) {
    printf("The array is hill shaped\n"); }
        else {
            printf("The array us not hill shaped\n"); }

    return 0;
}

void load_v(int v[])
{
    int i;

    printf("== welcome enter 8 number ==\n");
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber: ");
        scanf("%d",&v[i]);
    }
}

int hill_pattern(int v[])
{
    int i,peak = 0,type = 1;

    for (i = 0; i < dim-1; i++)
    {
            if (v[i] > v[i+1]) {
            peak = i;
            break; } 
    }
    int j;
    for (j = peak; j < dim-1; j++)
    {
        if (v[j] < v[j+1]) {
            type = 0; }
    }

    return type;
}
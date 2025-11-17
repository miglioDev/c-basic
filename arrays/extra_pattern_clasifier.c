// This program classifies the sequence as:
// strictly increasing, strictly decreasing, constant, alternating, or mixed.
// Usesing array
#include <stdio.h>
#define dim 8
int patter_check(int vect[]);

int main ()
{
    int i,result;
    int vect[dim] = {};

    printf("Welcome!\n enter 8 number");

    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&vect[i]);
    }

    result = patter_check(vect);
    if (result == 0)
    printf("The vector have a constant value\n");
        if (result == 1)
        printf("The vector have an increasing value\n");
            if (result == 2)
            printf("The vector have a decreasing value\n");
                if (result == 3)
                printf("The vector have an mixed pattern inc/dec\n");
                    if (result == 4)
                    printf("The vector is mixed");

    return 0;
}

int patter_check(int vect[])
{
    int c;
    int equal = 1,inc = 1,dec = 1,mix = 1,alt = 1;
    for (c = 0; c < dim-1; c++)
    {
        if (vect[c] >= vect[c+1]) inc = 0;
        if (vect[c] <= vect[c+1]) dec = 0;
        if (vect[c] != vect[c+1]) equal = 0;

            if (c > 0) //alt
            {
                int prev_jump = vect[c] - vect[c-1]; 
                int succ_jump = vect[c+1] - vect[c];
                if (prev_jump < 0 && succ_jump < 0) alt = 0;
                if (prev_jump > 0 && succ_jump > 0) alt = 0;
            }
    }
    if (equal) return 0;
    if (inc) return 1;
    if (dec) return 2;
    if (alt) return 3;
    else return 4;

    return 0;
}
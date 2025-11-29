/* This program loads a matrix from user input and verifies whether all elements
 * inside the matrix have the same value in a separate function that
 * returns 1 if the matrix is completely uniform, otherwise it returns 0.
 * */

#include <stdio.h>
#define R 3
#define C 3

void load(int m[][C]);
int equal(int m[][C]);

int main()
{
    int m[R][C];
    int v;

    load(m);
    v = equal(m);

    if(v) {
    printf("All values are equal!\n"); }
        else 
        printf("Matrix is not equal!\n");

    return 0;
}

void load(int m[][C])
{
    int r,c;

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            printf("\nEnter value in row: %d column: %d ",r,c);
            scanf("%d",&m[r][c]);
        }
    }
}

int equal(int m[][C])
{
    int T = 1;
    int r,c;

    for(r = 1; r < R; r++)
    {
        for(c = 1; c < C; c++)
        {
            if(m[r][c] != m[r-1][c-1]) T = 0;
        }
    }

    return T;
}
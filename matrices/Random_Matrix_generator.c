//This program initializes a square matrix with random integer values
//and print it on a formatted table with row and column index
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 4
#define C 4

void load_matrix(int m[][C]);
void f_printer(int m[][C]);

int main ()
{
    int m[R][C];

    load_matrix(m);
    f_printer(m);

    return 0;
}

void load_matrix(int m[][C])
{
    int r,c;
    srand(time(NULL));

    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            m[r][c] = rand();
        }
    }
}

void f_printer(int m[][C])
{
    int r,c,i;

    printf("==== Matrix Result ====\n");
    for (i = 0; i < R; i++)
    {
    printf("\t\t%d",i);
    }

    printf("\n");

    for (r = 0; r < R; r++)
    {
        printf("%d\t|\t",r);
        for (c = 0; c < C; c++)
        {
            printf("%d\t\t",m[r][c]);
        }
        printf("\n");
    }
}
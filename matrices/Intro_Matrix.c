// This program initializes a matrix, reads its values from user input,
// and prints the matrix to the screen
// practicing basic matrix handling 
#include <stdio.h>
#define R 4
#define C 3

void load_m(int m[R][C]);
void print_matrix(int m[R][C]);

int main ()
{
    int m[R][C];
    printf("== Welcome ==\n");

    load_m(m);

    printf("\nGood, now here is the Matrix:\n");
    print_matrix(m);

    return 0;
}

void load_m(int m[R][C])
{
    int r,c;
    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            printf("\nEnter the value of row: %d and column %d: ",r,c);
            scanf("%d",&m[r][c]);
        }
    }
}

void print_matrix(int m[R][C])
{
    int r,c;
    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}
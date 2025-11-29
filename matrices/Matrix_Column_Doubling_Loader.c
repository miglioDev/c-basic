//This program asks the user to insert the values for the first column of a matrix,
//then automatically fills the remaining columns by doubling the values of the
//previous column then prints the complete matrix with row and column index
#include <stdio.h> 
#define R 4
#define C 4

void load(int m[R][C]);
void visualize(int m[][C]);

int main ()
{
    int m[R][C];

    load(m);
    visualize(m);

    return 0;
}


void load(int m[R][C])
{
    int r,c;

    printf("== Enter value first column ==\n");
    for(r = 0; r < R; r++)
    {
        printf("\nEnter value of r %d c 0: ", r);
        scanf("%d", &m[r][0]);
    }

    for (r = 0; r < R; r++)
    {
        for (c = 1; c < C; c++)
        {
            m[r][c] = (m[r][c-1]*2);
        }
    }
}

void visualize(int m[][C])
{
    int r,c;

    for(c = 0; c < C; c++)
    {
        printf("\t%d",c);
    }
    printf("\n");

    for(r = 0; r < R; r++)
    {
        printf("%d |\t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}
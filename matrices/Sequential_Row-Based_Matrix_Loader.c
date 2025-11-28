// This program loads the first row of a matrix from user input and automatically
// fills the remaining rows by incrementing each value from the previous row

#include <stdio.h> 
#define R 4
#define C 4  

void load(int m[][C]);
void visual(int m[][C]);

int main ()
{
    int m[R][C];

    load(m);
    visual(m);

    return 0;
}

void load(int m[][C])
{
    int r,c;

    for (c = 0; c < C; c++)
    {
        printf("\nEnter value of c %d, and row %d ",c,1);
        scanf("%d",&m[0][c]);
    }

    for (r = 1; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            m[r][c] = m[r-1][c] +1;
        }
    }
}

void visual(int m[][C])
{
    int r,c;

    printf("\n\t");
    for(c = 0; c < C; c++)
    {
        printf("%d\t",c);
    }
    printf("\n");

    for (r = 0; r < R; r++)
    {
        printf("%d |\t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}

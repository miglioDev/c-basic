//This program fills a matrix with consecutive natural numbers starting from 1,
//arranged column by column (top to bottom), and then prints the matrix in
//a formatted layout.
#include <stdio.h>
#define R 5
#define C 5

void load(int m[][C]);
void visualize(int m[][C]);

int main()
{
    int m[R][C];
    
    load(m);
    visualize(m);

    return 0;
}

void load(int m[][C])
{
    int r,c,value = 1;

    for(c = 0; c < C; c++)
    {
        for(r = 0; r < R; r++)
        {
            m[r][c] = value;
            value++;
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
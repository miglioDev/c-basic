//This program fills a matrix with the classic multiplication table 
//(1×1, 1×2, ..., 10×10), AKA Pythagorean table. 
//It then prints the entire matrix in a formatted layout.
#include <stdio.h>
#define R 10
#define C 10

void load(int m[][C]);
void visualize(int m[][C]);

int main ()
{
    int m[R][C];

    load(m);
    visualize(m);

    return 0;
}

void load(int m[][C])
{
    int r,c;

    for(r = 1; r <= R; r++)
    {
        for(c = 1; c <= C; c++)
        {
            m[r][c] = (r*c);
        }
    }
}

void visualize(int m[][C])
{
    int r,c;

    for(c = 1; c <= C; c++)
    {
        printf("\t%d",c);
    }
    printf("\n");

    for(r = 1; r <= R; r++)
    {
        printf("%d |\t",r);
        for(c = 1; c <= C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}
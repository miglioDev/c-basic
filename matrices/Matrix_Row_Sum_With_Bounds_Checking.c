//This program fills a matrix with random integers, displays it
//with row and column indices, and computes the sum of the elements in a user-
//selected row, also check if the row index is out of range
#include <stdio.h> //es1
#include <stdlib.h>
#include <time.h> 
#define R 4
#define C 4

void load_ran(int m[][C]);
void visualize(int m[][C]);
int colum_and_check(int m[][C],int col);


int main ()
{
    int m[R][C];
    int col,result;
    
    load_ran(m);
    visualize(m);

    printf("Choose a column: ");
    scanf("%d",&col);
    result = colum_and_check(m,col);

    if (result == -1) {
    printf("Error invalid value\n"); }
        else 
        printf("the sum of the elemets in that colum is: %d\n",result);

    return 0;
}

void load_ran(int m[][C])
{
    int r,c;
    srand(time(NULL));

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            m[r][c] = rand();
        }
    }
}

void visualize(int m[][C])
{
    int r,c;

    printf("\n== Table of value: ==\n\t");
    for (c = 0; c < C; c++)
        printf("%d\t",c);
    printf("\n");
    for(r = 0; r < R; r++)
    {
        printf("%d\t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}

int colum_and_check(int m[][C],int col)
{
    int  sum = 0,r;
    if (col > C || col < 0)
        return -1;
        else { 
            for (r = 0; r < R; r++)
            sum = sum+m[r][C]; }
    
    return sum;
}
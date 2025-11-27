// this program fills a matrix with random two-digit integers, displays it with
// row and column indices, asks the user for a valid column index, find
// the maximum value contained in that column
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define R 3
#define C 4

void load(int m[][C]); 
void print_matrix(int m[][C]);
int column(int m[][C]);
int sum_col(int m[][C],int the_col);

int main ()
{
    int m[R][C];
    int the_col,result;

    load(m);
    print_matrix(m);
    the_col = column(m);
    result = sum_col(m,the_col);
    printf("\nThe top value of that column is %d \n",result);

    return 0;
}

void load(int m[][C])
{
    int r,c;
    srand(time(NULL));

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            m[r][c] = rand() %100;
        }
    }
}

void print_matrix(int m[][C])
{
    int r,c;

    for (c = 0; c < C; c++) 
    {
    printf("\t%d",c);
    }

    printf("\n");
    for(r = 0; r < R; r++)
    {
        printf("%d | \t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}

int column(int m[][C])
{
    int col;
    do
    {
        printf("Enter the value of the column to sum: ");
        scanf("%d",&col);
    }
    while(col < 0 || col > C);

    return col;
}

int sum_col(int m[][C],int the_col)
{
    int top = 0;
    int r;
    
    for(r = 0; r < R; r++)
    {
        if (r == 0) top = m[r][the_col];
            else { 
                if (m[r][the_col] > top)
                    top = m[r][the_col];
            }
    }

    return top;
}
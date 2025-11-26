//This program loads a matrix from user input, displays it with row and column
//indices, and computes the sum of all elements in a user-selected row.
#include <stdio.h>
#define R 3
#define C 3

void load(int m[][C]);
void visualize(int m[][C]);
int ask_user();
int sum_row(int m[][C],int x);

int main ()
{
    int m[R][C];
    int ROW, sum = 0;

    load(m);
    visualize(m);
    ROW = ask_user();
    sum = sum_row(m,ROW);

    printf("The sum of the row is %d",sum);

    return 0;
}

void load(int m[][C])
{
    int r,c;
    for (r = 0; r < R; r++)
    {
        for (c = 0; c < C; c++)
        {
            printf("Enter the value of row: %d column: %d: ",r,c);
            scanf("%d",&m[r][c]);
        }
    }
}

void visualize(int m[][C])
{
    int r,c;
    printf("\t");
    for(r = 0; r < R; r++) 
    {
    printf("%d\t",r);
    }
    printf("\n");
    for (r = 0; r < R; r++)
    {
        printf("%d\t",r);
        for (c = 0; c < C; c++)
        {
            printf("%d\t",m[r][c]);
        }
        printf("\n");
    }
}

int ask_user()
{
    int x = -1;
    do
    {
    printf("\nEnter the desired row to sum: ");
    scanf("%d",&x);
    }
    while(x > R || x < 0);
    return x;
}

int sum_row(int m[][C],int x)
{
    int sum,i;
    for (i = 0; i < R; i++)
    {
        sum = sum+m[x][i];
    }
    return sum;
}
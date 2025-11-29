//This program fills a matrix with two-digit random integers, displays it
//searches for a user-provided value, If the value is
//found, the program records the row and column otherwise print not found

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 4
#define C 5 

void load(int m[][C]);
void visualize(int m[][C]);
void find(int m[][C],int x, int *p_row, int *p_col);

int main ()
{
    int m[R][C];
    int x,c_row,c_col;
    int *p_row = &c_row;
    int *p_col = &c_col;

    load(m);
    visualize(m);

    printf("\nPick a number to find: ");
    scanf("%d",&x);

    find(m,x,&c_row,&c_col);
    if (*p_row >= 0|| *p_col >= 0)
        printf("Found: adress %d row and %d column\n",c_row,c_col);
    else 
        printf("Not found\n");

    return 0; 
}

void load(int m[][C])
{
    int r,c;
    srand (time(NULL));

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            m[r][c] = rand() %100;
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

void find(int m[][C],int x, int *p_row, int *p_col)
{
    int found = 0;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(m[r][c] == x) {
                found = 1;
                *p_row = r;
                *p_col = c;}
        }
    }
    if (!found) {
    *p_row = -1;
    *p_col = -1;
    }

}
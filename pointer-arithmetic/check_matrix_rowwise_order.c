// This program loads a matrix using pointer arithmetic 
// then checks whether its elements are in increasing order row by row.

#include <stdio.h>
#define R 3
#define C 3

void load(int (*m)[C]);
int pattern_chech(int (*m)[C]);

int main ()
{
    int m[R][C],is;

    load(m);
    is = pattern_chech(m);

    if(is) printf("\nThe values are in order\n");
    else    
        printf("\nNot in order\n");

    return 0;
}

void load(int (*m)[C])
{
    int i,j;

    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            printf("Enter the value in row %d column %d:  ",i,j);
            scanf("%d",*(m+i)+j);
        }
    }
}

int pattern_chech(int (*m)[C])
{
    int r,c,is_incr = 1;

    for(r = 0; r < R && is_incr; r++)
    {
        for(c = 0; c < C && is_incr; c++)
        {
            if(c == 0 && r > 0)
            if( *(*(m+r)+c) < *(*(m+r-1)+C-1)) is_incr = 0;

            if(c > 0)
            {
                if( *(*(m+r)+c) < *(*(m+r)+c-1)) is_incr = 0;
            }
        }
    }

    return is_incr;
}
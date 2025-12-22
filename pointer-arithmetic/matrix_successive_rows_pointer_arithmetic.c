// Program that loads a matrix using pointer arithmetic, 
// automatically fills rows with successive values, and displays row and column indices

#include <stdio.h>
#define R 4
#define C 4

void load(int (*m)[C]);
void visualize(int (*m)[C]);
 
int main ()
{
    int m[R][C];

    load(m);
    visualize(m);

    return 0;
}

void load(int (*m)[C])
{
    int r,c;
    for(c = 0; c < C; c++)
    {
        printf("\nEnter number row 0 column %d: ",c);
        scanf("%d", *m +c);
    }

    for(r = 1; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            *(*(m+r)+c) = *(*(m+r-1)+c) +1;
        }
    }
}

void visualize(int (*m)[C])
{
    int r,c;

    for(c = 0; c < C; c++)
    {
        printf("\t%d",c);
    }
    printf("\n");
    for(c = 0; c < C; c++)
    {
        printf("\t-");
    }
    printf("\n");

    for(r = 0; r < R; r++)
    {
        printf("%d|\t",r);
        for(c = 0; c < C; c++)
        {
            printf("%d\t", *(*(m+r)+ c));
        }
        printf("\n");
    }
}
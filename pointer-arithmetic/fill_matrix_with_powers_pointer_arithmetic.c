// Fills a matrix with successive powers of a base value using pointer arithmetic,
// practicing matrices loops and funct. without direct array indexing

#include <stdio.h>
#define R 3
#define C 3

void load(int (*m)[C]);
void complete(int (*m)[C]);
void visual(int (*m)[C]);

int main ()
{
    int m[R][C];

    load(m);
    complete(m);
    visual(m);

    return 0;
}

void load(int (*m)[C])
{
    printf("\nEnter a number: ");
    scanf("%d", *m);
}

void complete(int (*m)[C])
{
    int i,j;

    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            if(i == 0 && j == 0);

            else if(i > 0 && j == 0) {
                *(*(m+i)+j) = *(*(m+i-1)+C-1) * (**m);}
        
            else {
            *(*(m+i)+j) = *(*(m+i)+j-1) * (**m); }
        }
    }
}

void visual(int (*m)[C])
{
    int r,c;

    for(r = 0; r < R; r++)
    {
        printf("\t%d",r);
    }
    printf("\n      -----------------------\n");

    for(r = 0; r < R; r++)
    {
        printf("%d|",r);
        for(c = 0; c < C; c++)
        {
            printf("\t%d", *(*(m+r)+c) );
        }
        printf("\n");
    }
}
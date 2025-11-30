//This program loads a matrix from user input and checks whether its values,
//read row by row, are sorted in strictly increasing order
#include <stdio.h>
#define R 3
#define C 4

void load(int m[][C]);
int is_increasing(int m[][C]);

int main ()
{
    int m[R][C];
    int incr;

    load(m);
    incr = is_increasing(m);

    if(incr) { 
        printf("The Array is incresing!\n"); }
            else 
            printf("The Array is not increasing\n");

    return 0;
}

void load(int m[][C])
{   
    int r,c;

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            printf("\nEnter value of row:%d column:%d  ",r,c);
            scanf("%d",&m[r][c]);
        }
    }
}

int is_increasing(int m[][C])
{
    int t = 1;
    int r,c;

    for(r = 0; r < R; r++)
    {
        for(c = 0; c < C; c++)
        {
            if(c == 0 && r > 0) {
                if(m[0][r] < m[0][r-1]){
                    t = 0; }}
                if(c > 0) {
                    if(m[r][c] < m[r][c+1]) t = 0;}
        }
    }

    return t;
}
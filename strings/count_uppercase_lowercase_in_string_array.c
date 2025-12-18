// Counts the total number of uppercase and lowercase letters across an array of strings,
// practicing arrays of strings, pointers, and ctype.h fun.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define R 4
#define C 16

void load(char m[][C]);
void counter(char m[][C], int *p1, int *p2);

int main ()
{
    int x = 0,y = 0;
    char m[R][C];

    load(m);
    counter(m,&x,&y);

    printf("\nIn total there are:\n%d lowercase letter\n%d uppercase letter\n",x,y);

    return 0;
}

void load(char m[][C])
{
    for(int i = 0; i < R; i++)
    {
        printf("\nEnter string n.%d: ",i);
        scanf("%s", m[i]);
    }
}

void counter(char m[][C], int *p2, int *p1)
{
    int r,c,len;

    for(r = 0; r < R; r++)
    {
        len = strlen(m[r]);
        for(c = 0; c < len; c++)
        {
            if(isupper(m[r][c])) (*p1)++;
            if(islower(m[r][c])) (*p2)++;
        }
    }
}
// Program that manages an array of strings using pointer arithmetic,
// checks whether the strings are alphabetically ordered using strcmp,
// and prints the result.      Happy New Year 2026! 

#include <stdio.h>
#include <string.h>
#define R 4
#define C 16

void load(char (*m)[C]);
int order(char (*m)[C]);

int main ()
{
    int result;
    char m[R][C];

    load(m);
    result = order(m);

    if(result) printf("\nAre ordered\n");
    else 
        printf("\nNot ordered\n");

    return 0;
}

void load(char (*m)[C])
{
    int i;

    for(i = 0; i < R; i++)
    {
        printf("\nEnter string n.%d:  ",i);
        scanf("%s", *(m+i));
    }
}

int order(char (*m)[C])
{
    int r,is_ordered = 1;

    for(r = 0; r < R-1; r++)
    {
        if(strcmp(*(m+r), *(m+r+1)) >= 0) {
            is_ordered = 0;}
    }

    return is_ordered;
}
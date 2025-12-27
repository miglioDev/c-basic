// Checks whether a vector of strings is alphabetically ordered using strcmp and
// pointer arithmetic; practicing arrays, strings, and pointer-based access

#include <stdio.h>
#include <string.h>
#define R 4
#define C 14

void load(char (*m)[C]);
int order(char (*m)[C]);

int main ()
{
    int or;
    char m[R][C];

    load(m);
    or = order(m);
    if(or) printf("\nThe string are in order\n");
    else 
        printf("\nThe string are not in order\n");

    return 0;
}

void load(char (*m)[C])
{
    int i;
    for(i = 0; i < R; i++)
    {
        printf("Enter string numer %d: ",i);
        scanf("%s", *(m+i));
    }
}

int order(char (*m)[C])
{
    int i,is_ordered = 1;

    for(i = 0; i < R-1 && is_ordered; i++)
    {
    if(strcmp(*(m+i),*(m+i+1)) > 0)
    is_ordered = 0;
    }

    return is_ordered; 
}
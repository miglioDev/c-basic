// Reads an array of strings and checks whether all characters are lowercase using islower

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define R 5
#define C 18

void load(char m[][C]);
int only_lowercase(char m[][C]);

int main ()
{
    int r;
    char m[R][C];

    load(m);
    r = only_lowercase(m);
    if(r == 1) printf("There are only lower case letter\n");
    else printf("There is one ore more upper case letter\n");

    return 0;
}

void load(char m[][C])
{
    for(int r = 0; r < R; r++)
    {
        printf("\nEnter %d-string: ",r);
        scanf("%s", m[r]);
    }
}

int only_lowercase(char m[][C])
{
    int lower = 1,r,c,len;

    for(r = 0; r < R; r++)
    {
        len = strlen(m[r]);

        for(c = 0; c < len; c++)
        {
            if(isupper(m[r][c])) lower = 0;
        }
    }

    return lower;
}
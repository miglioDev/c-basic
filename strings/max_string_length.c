// Loads an array of strings and find the maximum string length using strlen,
// learning basic operations on arrays of strings

#include <stdio.h>
#include <string.h>
#define R 5
#define C 20

void load_string(char m[][C]);
int max(char m[][C]);

int main ()
{
    int r;
    char m[R][C];

    load_string(m);
    r = max(m);

    printf("\nThe max value of len is: %d \n",r);

    return 0;
}

void load_string(char m[][C])
{
    int i;
    for(i = 0; i < R; i++)
    {
        printf("Enter string in row %d: ",i);
        scanf("%s", m[i]);
    }
}

int max(char m[][C])
{
    int i,max,len;
    len = strlen(m[0]);
    max = len;

    for(i = 1; i < R; i++)
    {
        len = strlen(m[i]);
        if(max < len) max = len;
    }

    return max;
}
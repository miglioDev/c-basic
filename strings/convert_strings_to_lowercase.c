// Program that reads an array of strings, converts all uppercase letters to lowercase 
// and then prints each string with its index

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define R 5
#define C 16

void load(char m[][C]);
void convert(char m[][C]);
void visualize(char m[][C]);

int main ()
{
    char m[R][C];

    load(m);
    convert(m);
    visualize(m);

    return 0;
}

void load(char m[][C])
{
    for(int r = 0; r < R; r++)
    {
        printf("\nEnter string n.%d: ",r);
        scanf("%s", m[r]);
    }
}

void convert(char m[][C])
{
    int len,r,j;

    for(r = 0; r < R; r++)
    {
        len = strlen(m[r]);

        for(j = 0; j < len; j++)
        {
            if(isupper(m[r][j])) {
                m[r][j] = tolower(m[r][j]); }
        }
    }
}

void visualize(char m[][C])
{
    int r;
    for(r = 0; r < R; r++)
    {
        printf("\n%d) %s",r,m[r]);
    }
}
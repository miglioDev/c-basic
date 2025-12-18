// Concatenates all strings from an array into a single string using strcat,

#include <stdio.h>
#include <string.h>
#define C 12
#define R 4

void load(char m[][C]);
void merger(char m[][C], char s[]);

int main ()
{
    char m[R][C];
    char s[48] = {"\0"};

    load(m);
    merger(m,s);

    printf("\nThe resulting merged string is: %s\n",s);

    return 0;
}

void load(char m[][C])
{
    for(int i = 0; i < R; i++)
    {
        printf("\nEnter string: %d) ",i);
        scanf("%s", m[i]);
    }
}

void merger(char m[][C], char s[])
{
    int i;
    for(i = 0; i < R; i++)
    {
        strcat(s, m[i]);
    }
}
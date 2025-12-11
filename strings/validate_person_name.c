// This program reads a person's name and validates it if it has:
// at least three characters, start with an uppercase letter,
// and all remaining characters must be lowercase, im doing some string validation
// and character classification using ctype functions.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define dim 15

void load_name(char s[]); 

int main ()
{
    char s[dim];

    load_name(s);
    printf("Name: %s correct!\n",s);

    return 0;
}

void load_name(char s[])
{
    int len,cond2,ok;
    do
    {
    printf("Enter a name:");
    scanf("%s", s);
    len = strlen(s);

        cond2 = 0;
        for(int i = 1; i < len && cond2; i++)
        {
        if(!islower(s[i])) {
            cond2 = 0;}
        }
        ok = len > 3 && isupper(s[0]) && cond2;
        if (!ok) printf("Error- \n\n"); 
    }
    while(!ok);
}


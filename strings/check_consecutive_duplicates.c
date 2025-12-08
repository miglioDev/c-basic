// This program reads a string and checks whether it contains
// two identical consecutive letters 

#include <stdio.h>
#include <string.h>

int pattern(char s[]); 

int main ()
{
    int res;
    char s[15];
    printf("Enter a string: ");
    scanf("%s", s);

    res = pattern(s);

    if(res) printf("The string contain at least a pair of double letters\n");
        else 
        printf("There are no double letter in this string\n");

    return 0;
}

int pattern(char s[])
{
    char c;
    int len, result = 0;

    len = strlen(s);

    for(int i = 0; i < len-1 && !result; i++)
    {
        c = s[i];
        if(c == s[i+1]) result = 1;
    }

    return result;
}
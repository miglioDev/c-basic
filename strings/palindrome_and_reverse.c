// Checks whether a string is a palindrome by comparing symmetric characters
// and then reverses the string, to practice basic string manipulation logic 

#include <stdio.h>
#include <string.h>
#define dim 12

int is_pal(char s[]);
void reverse_string(char s[]);

int main ()
{
    int palind;
    char s[dim];
    printf("Enter a string\n");
    scanf("%s", s);

    palind = is_pal(s);
    if(palind) printf("The string is palindrome\n");
    else printf("The string is not palindrome\n");

    reverse_string(s);
    printf("The string reversed is: %s\n", s);

    return 0;
}

int is_pal(char s[])
{
    int len,i,j,is = 1;
    len = strlen(s);
    j = len-1;

    for(i = 0; i < len; i++)
    {
        if(s[i] != s[j]) is = 0;
        j--;
    }

    return is;
}

void reverse_string(char s[])
{
    int i,j,len;
    char k;
    len = strlen(s);
    j = len-1;

    for(i = 0; i < j; i++)
    {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
        j--;
    }
}
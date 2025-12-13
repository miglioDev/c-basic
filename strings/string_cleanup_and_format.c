// This program cleans a string by removing non-alphabetic characters,
// capitalizing the first letter and converting all others to lowercase

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define dim 12

int update_string(char s[]);
void size_update(char s[]);

int main ()
{
    int r;
    char s[dim];
    printf("Enter the string:");
    scanf("%s", s);

    r = update_string(s);
    if(r) size_update(s);

    if(r == 0) printf("The string is empty\n");
    else printf("The string updated is: %s\n", s);

    return 0;
}

int update_string(char s[])
{
    int is_letter,i,len,j;
    len = strlen(s);

    for( i = 0; i <= len; i++)
    {
        is_letter = isalpha(s[i]);
        if(is_letter == 0) 
            for(j = i; j < len; j++) 
                s[j] = s[j+1];
    }

    if(s[0] == '\0') return 0;
    else return 1;
}


void size_update(char s[])
{
    int i,len;
    len = strlen(s);

    s[0] = toupper(s[0]);
    for(i = 1; i < len; i++)
    {
        if(isupper(s[i])) {
            s[i] = tolower(s[i]);} 
    }
}
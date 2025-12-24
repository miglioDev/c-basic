// Program that adds a dot at the beginning and end of a string using pointer arithmetic,
// checking buffer size constraints 

#include <stdio.h>
#include <string.h>
#define dim 16

int update(char (*s));

int main ()
{
    int changed;
    char s[dim];

    printf("Enter a string: ");
    scanf("%s",s);

    changed = update(s);

    if(changed == 0) printf("The string can't be updated");
    else 
        printf("The string updated is %s",s);

    return 0;   
}

int update(char (*s))
{
    int len,updated,i;
    len = strlen(s);

    if(len >= dim-2) updated = 0;

    else {
        for(i = len+1; i > 0; i--)
        {
            *(s+i) = *(s+i-1);
        }
        *(s) = '.';
        *(s+len+1) = '.';
        *(s+len+2) = '\0';
        updated = 1;
    }

    return updated;
}
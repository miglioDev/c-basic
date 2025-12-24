// Program that removes the first and last character from a string using pointer arithmetic, 
// practicing string manipulation and conditional logic 

#include <stdio.h>
#include <string.h>
#define dim 16

int remov(char (*s));

int main ()
{
    int changed;
    char s[dim];

    printf("Enter a string: ");
    scanf("%s",s);

    changed = remov(s);

    if(changed) printf("\nThe string updated is: %s\n", s);
    else 
        printf("\nThe string can't be updated\n"); 

    return 0;
}

int remov(char (*s))
{
    int len,updated,i;
    len = strlen(s);

    if(*s == '\0') updated = 0;
    if(len < 2) updated = 0;
    else {
        for(i = 0; i < len; i++)
        {
            *(s+i) = *(s+i+1);
        }
        *(s+len-2) = '\0';
        updated = 1;
    }
    
    return updated;
}
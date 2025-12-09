// This program adds a leading and trailing dot to a string
// if enough space is available 
// practices manual string shifting 

#include <stdio.h>
#include <string.h>
#define dim 10

int add(char s[]);

int main ()
{
    int r;
    char s[dim];
    printf("Enter a string:");
    scanf("%s", s);

    r = add(s);
    
    if(r == 1) printf("\nThe string updated is: %s\n", s);
    else 
        printf("The string can't be updated\n");
    return 0;
}

int add(char s[])
{
    int len,i;
    len = strlen(s);

    if(len <= dim-3) {
            for(i = len; i >= 0; i--)
            {
                s[i+1] = s[i];
            }
            s[0] = '.';
            s[len+1] = '.';
            s[len+2] = '\0';

            return 1;}

    else {
        return 0; }
}
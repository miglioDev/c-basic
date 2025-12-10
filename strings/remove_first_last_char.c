// This program reads a string and removes its first and last characters
// if the string has at least two characters, string shifting 

#include <stdio.h>
#include <string.h>

int frem(char s[]);

int main ()
{
    int r;
    char s[10];
    
    printf("Enter a string:");
    scanf("%s", s);

    r = frem(s);
    if(s[0] == '\0') {printf("The string is empty");}
    else if(r == 1) { printf("\nThe string updated is %s\n", s);}
        else { printf("\nThe string can't be updated\n"); }

    return 0;
}

int frem(char s[])
{
    int i,len;
    len = strlen(s);

    if(len >= 2) { 
        for(i = 0; i < len; i++)
        {
            s[i] = s[i+1];
                if(i == len-2) {
                    s[i] = '\0'; }
        }
    return 1; }

    else return 0;
}
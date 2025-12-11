// This program removes the middle character of a string when the length is odd.

#include <stdio.h>
#include <string.h>

int remv(char s[]);

int main ()
{
    int r;
    char s[12];
    printf("Enter the string:");
    scanf("%s", s);

    r = remv(s);
    if (r == 1) {
    printf("The string updated is %s\n", s);}
        else 
        printf("The string can't be updated\n");

    return 0;
}

int remv(char s[])
{
    int i,updated,len; 
    len = strlen(s);

    if(len%2 == 0) {
        updated = 0;}
    else{
        for(i = len/2; i < len; i++)
        {
            s[i] = s[i+1];
            updated = 1;
        }}
    
    return updated; 
}
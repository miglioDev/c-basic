// Inserts a character in the middle of the string when its length is even,
// practicing partial right-shift of characters and safe string manipulation

#include <stdio.h>
#include <string.h>
#define dim 12

int add(char s[], char c);

int main ()
{
    int r;
    char c;
    char s[dim];
    printf("Enter a string:");
    scanf("%s", s);

    printf("\nPick an extra char to add: ");
    scanf("%c",&c);
    scanf("%c",&c);

    r = add(s,c);
    if(r == 1) {printf("The updated string is: %s", s);}
        else {printf("The string can't be updated"); }

    return 0;
}

int add(char s[], char c)
{
    int i,len,p;
    len = strlen(s);

    if(len%2 != 0 || len == dim-1) return 0;
    else {
        p = len/2; 
        for(i = len+1; i > len/2; i--)
        {
            s[i] = s[i-1];
        }
        s[p] = c;
        return 1;
    }
}
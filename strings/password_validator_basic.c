// This program asks the user to enter a password and validates it using string
// scanning and ctype functions, the password must include:
// at least 8 characters one upper && one lower case letter and 1 digit,
// The function loops until a valid password is provided.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define dim 15

void validator(char s[]);

int main ()
{
    char s[dim];

    validator(s);
    printf("== Password saved with success ==\n");

    return 0;
}

void validator(char s[])
{
    int len,i,one_upper,one_lower,one_digit,ok;
    do
    {
        printf("Enter a strong password:");
        scanf("%s",s);

        len = strlen(s);

        one_upper = 0;
        for(i = 0; i < len; i++)
        {
            if(isupper(s[i])) {
            one_upper = 1; }
        }

        one_lower = 0;
        for(i = 0; i < len; i++)
        {
            if(islower(s[i])) {
            one_lower = 1; }
        }

        one_digit = 0;
        for(i = 0; i < len; i++)
        {
            if(isdigit(s[i])) {
            one_digit = 1; }
        }

        ok = len > 8 && one_digit && one_upper && one_lower;
        if(!ok) printf("error --\n\n");
    }
    while(!ok);
}
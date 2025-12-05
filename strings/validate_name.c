// This program reads a name and validates it:
// - at least 3 characters long
// - first letter uppercase and all following letters lowercase
// it repeats input until all conditions are satisfied. */

#include <stdio.h>
#include <string.h>

void load(char s[]);

int main ()
{
    char s[12];

    load(s);
    printf("Nice! the name %s is in the correct format\n",s);

    return 0;
}

void load(char s[])
{
    int ok,len,condition1,condition2;
    do 
    {
        printf("Enter a name:\n");
        scanf("%s",s);

        len = strlen(s);
        if(s[0] >= 'A' && s[0] <= 'Z') condition1 = 1;

        condition2 = 1;
        for(int i = 1; i < len; i++)
        {
            if(!(s[i] >= 'a' && s[i] <= 'z')) condition2 = 0;
        }

        ok = (condition1 && condition2 && len >= 3);
        
        if(!ok)
            printf("Error -- non valid input --\n");
    }
    while(!ok);
}
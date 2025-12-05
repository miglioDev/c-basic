// this program is a Password validation program:
// it accepts only a password that meets all security rules
// then asks for confirmation both check keeps looping until you meet requirement
#include <stdio.h>
#include <string.h>
#define dim 15

void password(char s[]);
void confirm(char s[]);

int main()
{
    char s[dim];

    password(s);
    confirm(s);

    return 0;
}

void password(char s[])
{
    int ok,len,c1,c2,c3,c4,c5,c6;

    do
    {
    printf("Enter the password: ");
    scanf("%s", s);

    len = strlen(s);
    c1 = len >= 8;

    c2 = 0; c3 = 0, c4 = 0, c5= 0, c6= 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z') c2=1;
        if(s[i] >= 'A' && s[i] <= 'Z') c3=1;
        if(s[i] >= '0' && s[i] <= '9') c4=1;
        if(s[i] == '.' || s[i] == ',' || s[i] == ';' || s[i] == ':' || s[i] == '?'|| s[i] == '!') c5=1;
        if(s[i] == '@' || s[i] == '#' || s[i] == '*' || s[i] == '$' || s[i] == '%') c6=1;
    }
    
    ok = (c1 && c2 && c3 && c4 && c5 && c6);
      
    if (ok == 0) printf("Error --\n");

    } while (ok == 0);
}

void confirm(char s[])
{
    char c[dim];
    int i,len,equal;

    do 
    {
    equal = 1;

    printf("Comfirm the password:\n");
    scanf("%s", c);

    len = strlen(c);

    for(i = 0; i < len; i++)
    {
        if(s[i] != c[i]) equal = 0;
    }
    
    if (!equal) printf("-- Error --\n");

    } while(!equal);
}
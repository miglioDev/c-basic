/* The exercise I did today consists of a program that validates an alphabetical string, applies a circular
   Caesar shift that forward by k positions, prints
   the result, then shifts them back to restore the original string */ 

#include <stdio.h>
#include <string.h>
#define Dim 10

void load_string(char s[]); 
void cif(char s[],int code);
void decrip(char s[],int code);

int main ()
{
    char s[Dim];
    int code;

    load_string(s);

    printf("Enter cifrature code: ");
    scanf("%d", &code);

    cif(s, code);

    decrip(s, code);
    printf("\n == decripted ==\n %s", s);

    return 0;
}

void load_string(char s[])
{
    int i,len,ok = 1, lower, capital;

    do
    {
    printf("Enter a Word:  ");
    scanf("%s", s);

    len = strlen(s);

    for(i = 0; i < len; i++)
    {
        if(s[i] <= 'A' || s[i] >= 'Z') capital = 1;

        if(s[i] <= 'a' || s[i] >= 'z') lower = 1;

        if(capital && lower) ok = 1;

        if(!ok) printf("Error\n");
    }
    }
    while(ok == 0);
}

void cif(char s[],int code)
{
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < code; j++)
        {
            if (s[i] == 'z') {
            s[i] = 'a'; }
                    if (s[i] == 'Z') {
                    s[i] = 'A'; }
                        else 
                            s[i]++;
        }
    }
    printf("%s", s);
}

void decrip(char s[],int code)
{
    int i,j;
    int len = strlen(s);

    for(i = 0; i < len; i++)
    {
        for(j = 0; j < code; j++)
        {
            if(s[i] == 'z') {
            s[i] = 'a'; }
                if(s[i] == 'Z') {
                s[i] = 'A'; }
                    else 
                    s[i]--;   
        }
    }

}
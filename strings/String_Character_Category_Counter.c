// This program analyzes a user-provided string and counts how many characters
// are lowercase letters, uppercase letters, then prints the
// results using three dedicated functions.

#include <stdio.h>
#define dim 10

void counter(char s[]);
void capital(char s[]);
void under_score(char s[]);

int main ()
{
    char s[dim]; 
    printf("Hello, enter a word:\n");
    scanf("%s", s);

    counter(s);
    capital(s);
    under_score(s);

    return 0;
}

void counter(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++);
    printf("\nThe word contain %d",i);
}

void capital(char s[])
{
    int i,counter = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] => 'A' && s[i] <= 'Z') {
        counter++; }
    }

    printf("\nthe word have %d capital letter",counter);
}

void under_score(char s[])
{
    int i,counter = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if( s[i] >= 'a' && s[i] <= 'z') {
        counter++; }
    }

    printf("\nThe word have %d underscore letter\n",counter);
}
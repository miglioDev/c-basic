// this program clean a string by removing non-alphanumeric characters 
// and converting letters to lowercase, then count n of digit and letter in it
// this program practices string manipulation using ctype.h and string.h lib 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define dim 15

void clean_string(char s[]);
void counter(char s[], int *p1, int *p2);

int main ()
{
    char s[dim];
    int n_of_digit = 0, n_of_letter = 0;

    printf("Hello there enter a string: ");
    fgets(s, dim, stdin);

    printf("== String before the update ==\n");
    puts(s);

    clean_string(s);
    counter(s,&n_of_digit,&n_of_letter);

    printf("== String after the update ==\n");
    printf("%s\n", s);
    printf("Number of letter: %d\n", n_of_letter);
    printf("Number of digit: %d\n", n_of_digit);

    return 0; 
}

void clean_string(char s[])
{
    int i,j,len;
    len = strlen(s);

    for(i = 0; i < len; i++)
    {
        if(! (isalpha(s[i]) || isdigit(s[i])) ) {
            for(j = i; j < len; j++) 
            {
            s[j] = s[j+1];}
            }

        if(isupper(s[i])) {
            s[i] = tolower(s[i]);}
    }
}

void counter(char s[], int *p1, int *p2)
{
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        if(isalpha(s[i])) {
            (*p2)++;}

        if(isdigit(s[i])) {
            (*p1)++;}
    }
}
// Loads an array of strings from user input then counts how many strings
// start with an uppercase letter and end with a lowercase letter,
// practicing arrays of strings 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define C 21
#define row 5

void load(char m[][C]);
int counter(char m[][C]);

int main ()
{
    int c;
    char m[row][C];

    load(m);
    c  = counter(m);

    printf("\nThere are %d strings; with upper case letter as first char and lowercase letter as last char\n", c);
    return 0;
}

void load(char m[][C])
{
    int i;
    for(i = 0; i < row; i++)
    {
    printf("\nEnter string row %d: ",i);
    scanf("%s", m[i]);
    }
}

int counter(char m[][C])
{
    int i,len,counter = 0;
    for(i = 0; i < row; i++)
    {
        len = strlen(m[i]);
        if(isupper(m[i][0]) && islower(m[i][len-1])) {
        counter ++; }
    }

    return counter;
}
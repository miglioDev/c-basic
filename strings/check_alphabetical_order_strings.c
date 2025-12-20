// Reads an array of strings, checks if they are in alphabetical order using strcmp,
// and prints the strings


#include <string.h>
#include <stdio.h>
#define R 4
#define C 16

void load(char m[][C]);
int order(char m[][C]);

int main ()
{
    int p;
    char m[R][C];

    load(m);
    p = order(m);

    if(p == 1) printf("The string are in alphabetical order\n");
    else printf("The string are NOT in alphabetical oreder\n");

    return 0;
}

void load(char m[][C])
{
    for(int r = 0; r < R; r++)
    {
        printf("\nEnter string n.%d: ",r);
        scanf("%s", m[r]);
    }
}

int order(char m[][C])
{
    int r,alpha = 1;
    for(r = 1; r < R; r++)
    {
        if(strcmp(m[r], m[r-1]) <= 0) {
            alpha = 0; }
    }

    return alpha;
}
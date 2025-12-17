// Loads and displays an array of strings, then searches for a given word
// using strcmp to find the first and last occurrence

#include <stdio.h>
#include <string.h>
#define C 21
#define R 5

void load(char m[][C]);
void visualize(char m[][C]);
void find_string(int *p1, int *p2, char m[][C], char s[]);

int main ()
{
    int x = -1, y = -1;
    char s[19];
    char m[R][C];

    load(m);
    visualize(m);

    printf("Great now enter a string to find: ");
    scanf("%s", s);

    find_string(&x, &y, m, s);

    if(x == -1 || y == -1) printf("\nSub string not foud\n");
    if(x == y) printf("\nThere's one result at index: %d\n", x);
        else 
        printf("\nThe first result is %d and the last one is %d\n",x,y);

    return 0;
}

void load(char m[][C])
{
    printf("\n== Hello enter all the string in order ==\n");
    for(int i = 0; i < R; i++)
    {
        printf("\n%d) string: ",i);
        scanf("%s", m[i]);
    }
}

void visualize(char m[][C])
{
    int i;
    printf("===========================\n");

    printf("\nIndex:");
    for(i = 0; i < R; i++)
    {
        printf("\t%d", i);
    }

    printf("\nString:");
    for(i = 0; i < R; i++)
    {
        printf("\t%s", m[i]);
    }
    printf("\n");
}

void find_string(int *p1, int *p2, char m[][C], char s[])
{
    int i;
    for(i = 0; i < R; i++)
    {
        if(strcmp(m[i],s) == 0) {
            (*p1) = i;}
    }
    for(i = R-1; i != 0; i--)
    {
        if(strcmp(m[i],s) == 0) {
            (*p2) = i;}
    }
}

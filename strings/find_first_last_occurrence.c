// This program reads a string and a character, then identifies the index of
// the first and last occurrence of that character in the string (set -1 if absent)

#include <stdio.h>
#include <string.h>

void find(char s[], int *p1, int *p2, char c);

int main()
{
    char s[15];
    int n1,n2;
    int *p1 = &n1; 
    int *p2 = &n2;
    char c;

    printf("Enter a string:\n");
    scanf("%s", s);
    printf("\nGood now choose a letter:\n");
    scanf("%c", &c);
    scanf("%c", &c);

    find(s,&n1,&n2,c);

    if(*p1 == -1)  printf("The letter is not in the string\n");
    if(*p1 == *p2) printf("The letter appear once in the %d address\n", n1);
    if(*p1 != *p2) printf("The letter appear more than one time first at address %d and then at address %d\n", n1, n2);

    return 0;
}

void find(char s[], int *p1, int *p2, char c)
{
    int len;
    len = strlen(s);
    *p1 = -1;
    *p2 = -1;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == c && (*p1) == -1) *p1 = i;
        if(s[i] == c) *p2 = i;
    }
}
// this program reads a string from the user and create a second string
// containing each character from the original, but removing duplicate
// this ex. practices  duplicate detection and safe string building 

#include <stdio.h>
#include <string.h>
#define dim 10

void copy(char s1[], char s2[]);
int find(char c, char s2[]);

int main ()
{
    char s1[dim];
    char s2[dim];

    printf("Enter first string:\n");
    scanf("%s", s1);

    copy(s1, s2);

    printf("=========================\n");
    printf("first string: %s\n", s1);
    printf("second string: %s\n", s2);

    return 0;
}

void copy(char s1[], char s2[])
{
    int len,i,j,present;
    len = strlen(s1);

    j = 0;
    s2[0] = '\0';

    for(i = 0; i < len; i++)
    {
        present = find(s1[i], s2);
        if (!present) {
            s2[j] = s1[i];
            j++;
            s2[j] = '\0';
        }   
    }
}

int find(char c, char s2[])
{
    int i,P;
    P = 0;
    for(i = 0; s2[i] != '\0'; i++)
    {
        if(s2[i] == c) {
        P = 1; }
    }
    return P;
}
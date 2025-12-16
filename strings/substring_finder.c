// Checks whether a substring is contained inside another string using strstr,
// practicing basic string search with string.h functions.

#include <stdio.h>
#include <string.h>
#define dim 32

int sub_finder(char s1[], char s2[]);

int main ()
{
    int res;
    char s1[dim];
    char s2[dim-1];

    printf("Enter a string: ");
    scanf("%s", s1);

    printf("\nEnter the sub-string: ");
    scanf("%s", s2);

    res = sub_finder(s1,s2);

    if(res == 0) printf("Sub string not foud\n");
    else printf("The sub-string is present: %s\n", s2);

    return 0;
}

int sub_finder(char s1[], char s2[])
{
    char *result;

    result = strstr(s1, s2);

    if(result == NULL) return 0;
    else return 1;
}
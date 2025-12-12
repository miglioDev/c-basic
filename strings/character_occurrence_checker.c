// This program searches for a character in a string and reports whether it appears
// zero, one, or multiple times using strchr and strrchr (string searching practice).

#include <stdio.h>
#include <string.h>
#define dim 16

int find(char s[], char c);

int main ()
{
    char s[dim];
    char c;
    int r;

    printf("Enter a string: ");
    scanf("%s", s);

    printf("Enter a char: ");
    c = getchar();
    c = getchar();

    r = find(s,c);
    if(r == 0) printf("Char not found\n");
    if(r == 1) printf("Char found one time\n");
    if(r == 2) printf("Char found more than one time\n");

    return 0;
}

int find(char s[], char c)
{
    char *first, *last;
    int found;
    first = strchr(s, c);
    last = strrchr(s, c);

    if(first == NULL && last == NULL) {
    found = 0; }
    if(first == last) {
        found = 1;}

        else found = 2;
    return found;
}
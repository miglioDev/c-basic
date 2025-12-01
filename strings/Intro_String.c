//Basic String Input with character by character output
#include <stdio.h>

void ask(char s[20]);
void print(char s[20]);

int main()
{
    char s[20];

    ask(s);
    print(s);

    return 0;
}

void ask(char s[20])
{
    printf("\nEnter a word: ");
    scanf("%19s", s);
}

void print(char s[20])
{
    for(int i = 0; s[i] != '\0'; i++)
    {
    printf("%c", s[i]);
    }
}
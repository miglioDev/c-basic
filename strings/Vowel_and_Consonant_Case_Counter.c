// This program reads a string from the user and analyzes its characters to count
// lowercase and uppercase vowels, as well as lowercase and uppercase consonants.

#include <stdio.h>
#define Dim 10

void counter_one(char s[], int *p_lv, int *p_cv);
void counter_two(char s[], int *p_lc, int *p_cc);

int main()
{
    char s[Dim];
    int lower_vowels = 0, capital_vowels = 0, lower_consonants = 0, capital_consonants = 0;
    int *p_lv = &lower_vowels; 
    int *p_cv = &capital_vowels;
    int *p_lc = &lower_consonants; 
    int *p_cc = &capital_consonants;

    printf("Enter the word to check:\n");
    scanf("%s", s);

    counter_one(s, &lower_vowels, &capital_vowels);
    counter_two(s, &lower_consonants, &capital_consonants);

    printf("\n== STATS ==\nthe word entered (%s) have:\n", s);
    printf("%d lowercase vowels and %d capital vowels\n", lower_vowels, capital_vowels);
    printf("%d lowercase consonants and %d capital consonants\n", lower_consonants, capital_consonants);
    return 0;
}

void counter_one(char s[], int *p_lv, int *p_cv)
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            (*p_lv) ++;}
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            (*p_cv) ++;}
    }
}

void counter_two(char s[], int *p_lc, int *p_cc)
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
    {
        int low = s[i] >= 'a' && s[i] <= 'z';
        int cap = s[i] >= 'A' && s[i] <= 'Z';

        int vowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
        int vow_cap = (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U');

        if (low && !vowel) {
            (*p_lc)++;}
        if (cap && !vow_cap) {
            (*p_cc)++;}
    }
}
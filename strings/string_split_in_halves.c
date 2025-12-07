// This program reads one string and splits it into two halves:
// the first half is copied into s2 and the second half into s3
// It practices manual string separation without library helpers
#include <stdio.h>
#include <string.h>
#define dim 12

void copy_string(char s1[], char s2[], char s3[]);

int main ()
{
    char s1[dim]; 
    char s2[dim];
    char s3[dim];

    printf("Enter the first string:\n");
    scanf("%s", s1);

    copy_string(s1,s2,s3);

    printf("The first string is: %s\n", s2);
    printf("The second string is: %s\n", s3);

    return 0;
}

void copy_string(char s1[], char s2[], char s3[])
{
    int k, len, i,j;
    len = strlen(s1);
    k = len/2;

    j=0;
    for(i = 0; i < k; i++)
    {
        s2[i] = s1[i]; 
        j++;
    }
    s2[j] = '\0';

    j=0;
    for(i = k; i < len; i++)
    {
        s3[j] = s1[i];
        j++;
    }
    s3[j] = '\0';
}
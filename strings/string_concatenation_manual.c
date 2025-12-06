// This program reads two strings from the user and concatenates them into a third string.
// It practices manual string copying and concatenation without using library functions like strcat or copy.
#include <stdio.h>
#include <string.h>
#define dim 15

void copy_string(char s1[], char s2[], char s3[]);

int main ()
{
    char s1[dim];
    char s2[dim];
    char s3[dim+dim];

    printf("Hello there! enter the first string:\n");
    scanf("%s", s1);
    printf("Great no enter the second one:\n");
    scanf("%s", s2);

    copy_string(s1,s2,s3);

    printf("\nResult= %s\n", s3);

    return 0;
}

void copy_string(char s1[], char s2[], char s3[])
{
    int i,j = 0,len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);

    for(i = 0; i < len1; i++)
    {
        s3[i] = s1[i];
        j++;
    }

    for(i = 0; i < len2; i++)
    {
        s3[j] = s2[i];
        j++;
    }
}

// This program loads an array of strings starting from an user picked initial word 
// and generates the others by incrementing the last character

#include <string.h> 
#include <stdio.h>
#define C 15
#define R 5

void load(char m[][C]);
void visualize(char m[][C]);

int main ()
{
    char m[R][C];
    
    load(m);
    visualize(m);

    return 0;
}

void load(char m[][C])
{
    int i,len;
    char c;

    printf("Enter the first string: ");
    scanf("%s", m[0]);
    len = strlen(m[0]);

    for(i = 1; i < R; i++)
    {
        strcpy(m[i],m[0]);

        c = m[i-1][len-1];
        c++;
        m[i][len-1] = c;
    }
}

void visualize(char m[][C])
{
    int i;
    
    for(i = 0; i < R; i++)
    {
        printf("%d) %s\n",i,m[i]);
    }
}
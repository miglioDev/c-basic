// Program that fills a vector of strings using pointer arithmetic by incrementing the last character of the first string 
// then and displays the strings in order -Merry Christmas 2025 

#include <stdio.h>
#include <string.h>
#define R 4
#define C 18

void load(char (*m)[C]);
void visual(char (*m)[C]);

int main ()
{
    char m[R][C];

    load(m);
    visual(m);

    return 0;
}

void load(char (*m)[C])
{
    int i,len;
    
    for(i = 0; i < R; i++)
    {
    len = strlen(*m);

    if(i == 0) {  
    printf("Enter the first string: ");
    scanf("%s", *(m+i)); }

    else {
        strcpy(*(m+i), *(m+i-1));
        (*(*(m+i)+len-1))++; }
    }
}

void visual(char (*m)[C])
{
    int i;

    printf("\n---------------------");
    for(i = 0; i < R; i++)
    {
        printf("\n%s",*(m+i));
    }
    printf("\n---------------------");
}
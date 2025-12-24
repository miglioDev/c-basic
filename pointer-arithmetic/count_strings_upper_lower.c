// Program that counts how many strings start with an uppercase letter and end with a lowercase letter
// (using pointer arithmetic)

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define R 4
#define C 16

void load(char (*m)[C]);
int counter(char (*m)[C]);

int main ()
{
    int n;
    char m[R][C];
    
    load(m);
    n = counter(m);

    printf("There are %d string with that condition\n", n);

    return 0;
}

void load(char (*m)[C])
{   
    for(int i = 0; i < R; i++)
    {
        printf("Enter string n.%d: ",i);
        scanf("%s", *(m+i));
    }
}

int counter(char (*m)[C])
{
    int num = 0,i,len;

    for(i = 0; i < R; i++)
    {
        len = strlen(*(m+i));
        if(isupper(**(m+i)) && islower(*(*(m+i)+len-1))) num++;
    }

    return num;
}
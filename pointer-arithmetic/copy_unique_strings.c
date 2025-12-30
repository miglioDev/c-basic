// Manages arrays of strings using pointer arithmetic, loads strings, removes duplicates
// while copying from one array to another, and fills remaining slots with empty strings

#include <stdio.h>
#include <string.h>
#define R 4
#define C 16 

void load_s(char (*m)[C]);
void copy_string(char (*m1)[C], char (*m2)[C]);
void visualize(char (*m)[C]);

int main ()
{
    char s1[R][C];
    char s2[R][C];

    load_s(s1);
    copy_string(s1,s2);
    visualize(s2);

    return 0;
}

void load_s(char (*m)[C])
{
    int r;
    for(r = 0; r < R; r++)
    {
        printf("\nEnter string n.%d: ",r);
        scanf("%s", *(m+r));
    }
}

void copy_string(char (*m1)[C], char (*m2)[C])
{
    int r,j,counter = 0, found;

    for(j = 0; j < R; j++)
    {
        found = 0;

        for(r = 0; r < R && !found; r++)
        {
        if(strcmp(*(m1+j),*(m2+r)) == 0) found = 1;
        }

        if(!found) {
        strcpy(*(m2+counter),*(m1+j));
        counter ++; }
    }

    while(counter < R) 
    {
        **(m2+counter) = '\0';
        counter++;
    }
}

void visualize(char (*m)[C])
{
    int r;
    
    for(r = 0; r < R; r++)
    {
        printf("%d) %s\n",r, *(m+r));
    }
}
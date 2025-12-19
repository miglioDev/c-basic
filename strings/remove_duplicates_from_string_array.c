// Copies strings from one array to another while removing duplicates,
// practicing string comparison and controlled copying

#include <stdio.h>
#include <string.h>
#define R 4
#define C 19

void load(char m1[][C]);
void str_copy(char m1[][C], char m2[][C]);
void str_copy(char m1[][C], char m2[][C]);
void visual(char m1[][C], char m2[][C]);

int main ()
{
    char m1[R][C];
    char m2[R][C];

    load(m1);
    str_copy(m1,m2);
    visual(m1,m2);
    
    return 0;
}

void load(char m1[][C])
{   
    for(int r = 0; r < R; r++)
    {
        printf("\nEnter %d- string: ",r);
        scanf("%s",m1[r]);
    }
}

void str_copy(char m1[][C], char m2[][C])
{
    int i,j,k, is_there;
    k = 0;

    for(i = 0; i < R; i++)
    {
        is_there = 0;

        for(j = 0; j < k; j++)
        {
            if(strcmp(m1[i], m2[j]) == 0) {
            is_there = 1; }
        }

        if(!is_there) {
            strcpy(m2[k],m1[i]);
            k++;
        }
    }
    while(k < R)
    {
        m2[k][0] = '\0';
        k++;
    }

}

void visual(char m1[][C], char m2[][C])
{
    int r;
    
    printf("\n===== m1 ====\n");
    for(r = 0; r < R; r++)
    {
        printf("%d) %s\n",r,m1[r]);
    }

    printf("\n===== m2 ====\n");
    for(r = 0; r < R; r++)
    {
        printf("%d) %s\n",r,m2[r]);
    }
}
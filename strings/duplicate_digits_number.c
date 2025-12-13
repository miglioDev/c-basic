// Converts an integer to a string, duplicates each digit if the buffer allows it,
// converts the result back to an integer, and practices string–number manipulation.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define dim 16

int conver(int x);

int main ()
{   
    int x,res;
    printf("Enter a number:\n");
    scanf("%d",&x);

    res = conver(x);
    if(res == 0) printf("The string can't be updated\n");
    else 
        printf("The string updated is %d ", res);

    return 0;
}

int conver(int x)
{
    int len,pos_overflow = 0,neg_overflow = 0,w,i,j,R;
    char s[dim];
    sprintf(s,"%d",x);

    len = strlen(s);
    pos_overflow = (isdigit(s[0]) && len*2 > dim-1);
    neg_overflow = (s[0] == '-' && 1+(len-1)*2 > dim-1);

    if(pos_overflow || neg_overflow) R = 0;

    else {
        if(isdigit(s[0])) w = 0;
        else w = 1;

    for(i = w; s[i] != '\0'; i=i+2)
    {
        len = strlen(s);
        for(j = len+1; j > i; j--)
        {
            s[j] = s[j-1]; 
        }
    }
    sscanf(s, "%d", &R);}

    return R;
}


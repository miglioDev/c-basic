// recursive power function computing x^y  (repeated multiplication)
#include <stdio.h>

int pwr(int x, int y);

int main ()
{
    int res,x,y;

    printf("\n== Power Calculator ==\n");
    printf("\nEnter x: ");
    scanf("%d",&x);

    printf("\nEnter y: ");
    scanf("%d",&y);

    res = pwr(x,y);
    printf("\nResult = %d",res);

    return 0;
}

int pwr(int x, int y)
{
    if(y == 0) {
        return 1; }

    else {
        return x * pwr(x,y-1); }
}
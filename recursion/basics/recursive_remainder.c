// Recursive computation of remainder using repeated subtraction
#include <stdio.h>

int r_remainder(int x, int y);

int main ()
{
    int res,x,y;

    printf("\n== division remainder ==\n");
    printf("\nEnter x: ");
    scanf("%d",&x);

    printf("\nEnter y: ");
    scanf("%d",&y);

    res = r_remainder(x,y);
    printf("\nResult = %d",res);

    return 0;
}

int r_remainder(int x, int y)
{
    if(x < y) {
        return x; }

    else {
        return r_remainder(x-y,y);
    }
}

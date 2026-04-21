// recursive integer division via repeated subtraction
#include <stdio.h>

int division(int x, int y);

int main ()
{
    int res,x,y;

    printf("\n== recursive division ==\n");
    printf("\nEnter x: ");
    scanf("%d",&x);

    printf("\nEnter y: ");
    scanf("%d",&y);

    res = division(x,y);
    printf("\nResult = %d",res);

    return 0;
}

int division(int x, int y)
{
    if(x < y) {
        return 0; }
    
    else {
        return 1 + division(x-y,y); }
}

//recursive sum of two integers using repeated increment
#include <stdio.h>

int recursive_sum(int x, int y);

int main ()
{
    int res,x,y;

    printf("\n== Sum recursive ==\n");
    printf("\nEnter x: ");
    scanf("%d",&x);

    printf("\nEnter y: ");
    scanf("%d",&y);

    res = recursive_sum(x,y);
    printf("\nResult = %d",res);

    return 0;
}

int recursive_sum(int x, int y)
{
    if(y == 0) {
        return x; }
    else {
        return 1 + recursive_sum(x,y-1); }
}
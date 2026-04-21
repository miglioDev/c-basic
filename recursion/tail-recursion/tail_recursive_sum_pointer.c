// Tail-recursive sum using external accumulator pointer
#include <stdio.h>

void rec_tail_sum(int x, int y, int *acc);

int main ()
{
    int x,y;
    int acc = 0;

    printf("\n== Sum tail recursive ==\n");
    printf("\nEnter x: ");
    scanf("%d",&x);

    printf("\nEnter y: ");
    scanf("%d",&y);

    rec_tail_sum(x,y,&acc);
    printf("\nResult = %d",acc);

    return 0;
}

void rec_tail_sum(int x, int y, int *acc)
{
    if(y == 0) {
        *acc = (*acc) + x; }

    else {
        *acc = (*acc) + 1;
        return rec_tail_sum(x,y-1,acc); }
}


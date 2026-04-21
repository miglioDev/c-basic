// Recursive product via repeated addition
#include <stdio.h>

int recursive_product(int x, int y);

int main ()
{
    int res,x,y; 
    printf("\n== product recursive ==\n"); 
    printf("\nEnter x: "); 
    scanf("%d",&x); 
    printf("\nEnter y: "); 
    scanf("%d",&y); 
    
    res = recursive_product(x,y); 
    printf("\nResult = %d",res); 
    return 0;
}

int recursive_product(int x, int y)
{
    if(y == 0) {
        return 0; }
    else {
        return x+recursive_product(x,y-1); }
}
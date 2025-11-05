/*
 * this program reads an integer and uses pointer-based functions to
 * calculate its half (as float) and its double. Demonstrates how pointers
 * allow modifying and reading a variable's value directly in memory.
 */
#include <stdio.h>
float half(int *p);
void fun_double(int *p);
int main ()
{
    int x;
    printf("=== Welcome ===\n Enter the initial value:");
    scanf("%d",&x);
    int *p = &x;
    printf("\nInitial value: %d\taddress: %p",x,(void*)p);
    float k = half(p);
    printf("\nValue after halving: %f\t address: %p",k,(void*)p);
    fun_double(p);
    printf("\nValue after doubling: %d\t address: %p",x,(void*)p);
    return 0;
}
float half(int *p)
{
    return (float)(*p)/2.0f;
}
void fun_double(int *p)
{
    (*p) = (*p)*(2);
}
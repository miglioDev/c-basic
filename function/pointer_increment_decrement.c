/*
 * Reads an integer and uses pointer-based functions to
 * increment and decrement its value. Demonstrates how dereferencing (*)
 * allows modification of a variable's value directly in memory.
 */
#include <stdio.h>
void show_value(int *p);
void increment_addr(int *p);
void decrement_addr(int *p);
int main ()
{
    int x;
    printf("== Welcome! ==\nEnter a number: ");
    scanf("%d",&x);
    int *p = &x;
    show_value(p);
    printf("\n== Let's increment the function: ==\n");
    increment_addr(p);
    show_value(p);
    printf("\n== Let's now decrement the function: ==\n");
    decrement_addr(p);
    show_value(p);
    return 0;
}
void show_value(int *p)
{
    int n = *p;
    printf("the value of x is now %d",n);
    printf("\nthe address of x is now %p\n", (void*)p);
}
void increment_addr(int *p)
{
    (*p) ++;
}
void decrement_addr(int *p)
{
    (*p)--;
    (*p)--;
}
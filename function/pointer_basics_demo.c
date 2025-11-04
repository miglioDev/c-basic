/*
 * This Demonstrates how pointers work by showing a variable's
 * address and value, and then modifying the value through its pointer.
 * Introduces concept i learned today dereferencing (*) and address-of (&) operators.
 */
#include <stdio.h>
void welcome();
void show_value(int *p);
void new_value(int *p);

int main ()
{
    int x;
    welcome();
    scanf("%d",&x);
    int *p = &x;
    show_value(&x);
    new_value(p);
    show_value(&x);
    return 0;
}
void welcome()
{
    printf("=== Welcome! ===\n");
    printf("Enter a number:");
}
void show_value(int *p)
{
    printf("address:%p\n", (void*)p);
    printf("value stored:%d\n",*p);
}
void new_value(int *p)
{
    int new_value;
    printf("\nGreat, now enter a new value:");
    scanf("%d",&new_value);
    *p = new_value;
}
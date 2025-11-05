/*
 * this program demonstrates the concept of pass-by-reference in C.
 * reads two integers, displays their values and addresses,
 * swaps them using a pointer-based function, and shows the updated values (im learning pointer)
 */
#include <stdio.h>
void welcome();
void swap(int *p_one,int *p_two);
void show_value(int *p_one,int *p_two);

int main ()
{
    int x,y;
    welcome();
    printf("Enter number one:\n");
    scanf("%d",&x);
    printf("Enter the second number:\n");
    scanf("%d",&y);
    int *p_one = &x;
    int *p_two = &y;

    printf("before swap:\n");
    show_value(p_one,p_two);
    swap(&x,&y);
    printf("\nafter swap:\n");
    show_value(p_one,p_two);
}

void welcome()
{
    printf("== Welcome!! ==\n");
}

void swap(int *p_one,int *p_two)
{
    int k;
    k = *p_one;
    *p_one = *p_two;
    *p_two = k;
}
void show_value(int *p_one,int *p_two)
{
    printf("the first value is: %d\n",*p_one);
    printf("the address of that value is: %p\n",(void*)p_one);
    printf("the second value is: %d\n",*p_two);
    printf("the address of that value is: %p\n",(void*)p_two);
}
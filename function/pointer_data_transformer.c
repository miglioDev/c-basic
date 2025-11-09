/*
 * Reads three integers and manipulates them using pointer-based
 * pass-by-reference. Swaps the first two values, doubles the third, increases
 * the largest value by 5, and decreases the smallest by 3. 
 */
#include <stdio.h>
void transform_fun(int *p, int *p2, int *p3, int *o_1, int *o_2);
int main ()
{
    int a,b,c,output1,output2;
    int *o_1 = &output1;
    int *o_2 = &output2;

    printf("Enter the first value: ");
    scanf("%d",&a);
    printf("\nEnter the second value: ");
    scanf("%d",&b);
    printf("\nEnter the third value: ");
    scanf("%d",&c);

    printf("== Before ==\n");
    printf("variable:\tvalue:\taddress:\n");
    printf("a\t%d\t%p\n",a,&a);
    printf("b\t%d\t%p\n",b,&b);
    printf("c\t%d\t%p\n",c,&c);

    transform_fun(&a,&b,&c,&output1,&output2);
    printf("== After ==\n");
    printf("a\t%d\t%p\n",a,&a);
    printf("b\t%d\t%p\n",b,&b);
    printf("c\t%d\t%p\n",c,&c);
    printf("the biggest one +5 is: %d\n",*o_1);
    printf("the smallest one -3 is: %d\n",*o_2);

    return 0;
}
void transform_fun(int *p, int *p2, int *p3, int *o_1, int *o_2)
{
    int k,greater,smallest;
    k = *p;
    *p = *p2;
    *p2 = k;

    *p3 = (2)*(*p3);

    greater = *p;
    if (*p2 > greater) greater = *p2;
    if (*p3 > greater) greater = *p3;
 

        smallest = *p;
        if (smallest > *p2)
            smallest = *p2;
        if (smallest > *p3)
            smallest = *p3;

    *o_1 = greater +5;
    *o_2 = smallest -3;
}
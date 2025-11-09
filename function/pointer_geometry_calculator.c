/*
 * This program calculates the hypotenuse, perimeter, and area of a right-angled
 * triangle using pointer-based data manipulation. Demonstrates pass-by-reference
 * with mathematical operations and memory address tracking.
 */
#include <stdio.h>
#include <math.h>
void triangle(int *p_a,int *p_b, float *p_hyp, float *p_per, float *p_area);
int main ()
{
    int a,b;
    float perimeter,hyp,area;

    printf("Insert the sides of the right-angled triangle:\nside a: ");
    scanf("%d",&a);
    printf("\nside b: ");
    scanf("%d",&b);
    triangle(&a,&b,&hyp,&perimeter,&area);

    printf("== Data analysis ==\n");
    printf("\ndata:\tvalue:\tadress:\n");
    printf("a\t%d\t%p\n",a,&a);
    printf("b\t%d\t%p\n",b,&b);
    printf("hypotenuse\t%.4f\t%p\n",hyp,&hyp);
    printf("perimeter\t%.4f\t%p\n",perimeter,&perimeter);
    printf("area\t%.4f\t%p\n",area,&area);

    return 0;
}


void triangle(int *p_a,int *p_b, float *p_hyp, float *p_per, float *p_area)
{
    *p_hyp = sqrt((*p_a)*(*p_a)+(*p_b)*(*p_b));
    *p_per = (*p_a)+(*p_b)+(*p_hyp);
    *p_area = ((*p_a)*(*p_b))/2;
}
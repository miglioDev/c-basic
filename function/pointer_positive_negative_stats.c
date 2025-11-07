/*
 * Today code reads a series of integers and calculates the sum,
 * count, and average of positive and negative numbers using pointers
 * to share and modify data between functions.
 */
#include <stdio.h>
void the_counter(int *p,int *p_counter_pos,int *p_counter_neg);
void average_fun(float sum_pos,float sum_neg,int *p_counter_pos,int *p_counter_neg,float *p_res_p,float *p_res_n);

int main ()
{
    int n,x,i;
    float sum_pos,sum_neg;
    sum_pos = 0; sum_neg = 0;
    int counter_pos = 0;
    int counter_neg = 0;
    float res_p = 0;
    float res_n = 0;

    float *p_res_p = &res_p;
    float *p_res_n = &res_n;
    int *p_counter_pos = &counter_pos;
    int *p_counter_neg = &counter_neg;


    printf("How many numbers will you enter?\n");
    scanf("%d",&n);
    int *p = &x;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter number:");
        scanf("%d",&x);
        if (x > 0)
            {
            sum_pos = sum_pos + x;
            }
            else if (x < 0)
            {
                sum_neg = sum_neg + x;
            }
        the_counter(p,p_counter_pos,p_counter_neg);
    }
    average_fun(sum_pos,sum_neg,p_counter_pos,p_counter_neg,p_res_p,p_res_n);

    printf("== result ==\n");
    printf("The sum of all the positive integer is:%2f\n",sum_pos);
    printf("The sum of all the negative integer is:%2f\n",sum_neg);
    printf("The average of the positive integer is:%2f\n",res_p);
    printf("The average of the negative integer is:%2f\n",res_n);

    return 0;
}

void the_counter(int *p,int *p_counter_pos,int *p_counter_neg)
{
       if ((*p) > 0)
        {
            (*p_counter_pos) ++;
        }
        else if ((*p) < 0)
        {
            (*p_counter_neg) ++;
        } 
}
void average_fun(float sum_pos,float sum_neg,int *p_counter_pos,int *p_counter_neg,float *p_res_p,float *p_res_n)
{
    (*p_res_p) = (sum_pos)/(*p_counter_pos);
    (*p_res_n) = (sum_neg)/(*p_counter_neg);
}
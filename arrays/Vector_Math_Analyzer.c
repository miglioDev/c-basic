// Reads a user-defined list of integers and computes total sum, average,
// maximum and minimum values, and how many elements are divisible by 3.
// Pracitise on arrays functions and returning multiple results

#include <stdio.h>
void analyze_vector(float *p_sum, float *p_avg, float *p_big, float *p_small,float *p_th,int *p_n,int vector[50]);

int main ()
{
    int vector[50] = {};
    int n,valid = 0,counter;
    float sum = 0,average = 0,biggest = 0,smallest = 0,m_of_three = 0;
    float *p_sum = &sum;
    float *p_avg = &average;
    float *p_big = &biggest;
    float *p_small = &smallest;
    float *p_th = &m_of_three;


    printf("== Welcome ==\n");
    printf("How many number will you enter?\n");
    scanf("%d",&n);
    if (n < 0 && n > 50) valid = 1;

    if (valid != 1)
    do 
    {
    printf("How many number will you enter?\n range=(0-50)\n");
    scanf("%d",&n);
    if (n < 0 || n > 50) valid = 1;
    }
    while (n < 0 && n > 50);


    printf("Perfect now enter you number in order:\n");
    for (counter = 0; counter < n; counter ++)
    {
        printf("Number:\n");
        scanf("%d",&vector[counter]);
    }
    int *p_n = &n;
    analyze_vector(&sum,&average,&biggest,&smallest,&m_of_three,&n,vector);

    printf("== Result ==\n");
    printf("sum = %f\n",sum);
    printf("average = %f\n", average);
    printf("smallest = %f\n", smallest);
    printf("biggest = %f\n", biggest);
    printf("divisible by three = %f\n",m_of_three);

    return 0;
}

void analyze_vector(float *p_sum, float *p_avg, float *p_big, float *p_small,float *p_th,int *p_n,int vector[50])
{
    int i = 0,n;
    n = (*p_n);

    *p_big = vector[0];
    *p_small = vector[0];


    for (; i < n; i++)
    {
        if (vector[i] > *p_big) *p_big = vector[i];
        if (vector[i] < *p_small) *p_small = vector[i];
        *p_sum = *p_sum + vector[i];
        if (vector[i]%3 == 0)
            (*p_th) ++;
    }
    *p_avg = (*p_sum)/n;
}
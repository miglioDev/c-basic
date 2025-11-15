// Today program reads 10 integers into an array and computes multiple statistics
//Demonstrates modular design with arrays and pointer-based parameter passing in C

#include <stdio.h>
#include <math.h>
#define dim 10

float sum_calc(int arr[]);
float average_calc(float *p_sum);
void max_min(int arr[],int *p_max, int *p_min);
void even_odd_counter (int arr[],int *p_even, int *p_odd);
int greater_than_avg(int arr[],float average);
void abs_transform(int arr[],int abs_arr[]);
int check_arr(int arr[], int abs_arr[]);


int main ()
{
    int arr[dim] = {};
    int abs_arr[dim] = {};
    int i = 0,both_arr_equal;
    //output
    int max = 0,min = 0,even_count = 0,odd_count = 0,greater_than_average;
    float sum = 0,average;

    printf("Welcome! \n I will ask you to enter 10 numbers:\n");
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }

    sum = sum_calc(arr);

    average = average_calc(&sum);

    int *p_max = &max; 
    int *p_min = &min; 
    max_min(arr,&max,&min);

    int *p_even = &even_count;
    int *p_odd = &odd_count;
    even_odd_counter (arr,&even_count,&odd_count);

    greater_than_average = greater_than_avg(arr,average);

    abs_transform(arr,abs_arr);

    both_arr_equal = check_arr(arr,abs_arr);

    //result
    printf("=== FINAL REPORT ===\n");
    printf("Sum = %f\n",sum);
    printf("Average = %f\n",average);
    printf("Max = %d\n",max);
    printf("Min = %d\n",min);
    printf("Even numbers = %d\n",even_count);
    printf("Odd numbers = %d\n",odd_count);
    printf("Numbers greater than average: %d",greater_than_average);

    if (both_arr_equal) 
        printf("The arrays is and its absolute value are equal\n");
        else 
            printf("The arrays are different\n");
    
    printf("Original Vector:\n");
        for (i = 0; i < dim; i ++)
        {
            printf("Addres: %d ",i);
            printf("value: %d\t", arr[i]);
        }
        printf("\nVector abs:\n");
            for (i = 0; i < dim; i ++)
            {
                printf("Addres: %d ",i);
                printf("value: %d\t", abs_arr[i]);
            }

    return 0;
}

float sum_calc(int arr[])
{
    int i,the_sum = 0;
    for (i = 0; i < dim; i++)
    {
        the_sum = the_sum + arr[i];
    }
    return the_sum;
}

float average_calc(float *p_sum)
{
    float r = (*p_sum)/(dim);
    return r;
}

void max_min(int arr[],int *p_max, int *p_min)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        if ( i == 0 )
        {
            *p_max = arr[i];
            *p_min = arr[i];
        }
            else 
            {
                if (arr[i] > (*p_max))
                    *p_max = arr[i]; 
                if (arr[i] < (*p_min))
                    *p_min = arr[i];
            }
    }
}



void even_odd_counter (int arr[],int *p_even, int *p_odd)
{
    int i,is_even = 0,is_odd = 0;
    for (i = 0; i < dim; i++)
    {
        if (arr[i]%2 == 0)
            is_even = 1;
            else 
                is_even = 0;
        if (arr[i]%2 != 0)
            is_odd = 1;
            else 
                is_odd = 0;
        if (is_even) {
            (*p_even)++;}
        if (is_odd) {
            (*p_odd)++;}
    }
}

int greater_than_avg(int arr[],float average)
{
    int number = 0,i;
    for (i = 0; i < dim; i++)
    {
        if (arr[i] > average)
            number ++;
    }
    return number;
}


void abs_transform(int arr[],int abs_arr[])
{
    int i,x,abs_x;
    for (i = 0; i < dim; i ++)
    {
        x = arr[i];
        abs_x = abs(x);
        abs_arr[i] = abs_x;
    }
}

int check_arr(int arr[], int abs_arr[])
{
    int equal = 1;
    int i = 0;
    for (; i < dim; i++)
    {
        if (arr[i] != abs_arr[i])
        {
            equal = 0;
        }
    }
    return equal;
}
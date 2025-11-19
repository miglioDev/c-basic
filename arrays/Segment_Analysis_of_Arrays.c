// Program that reads an integer array and computes the sum, minimum,
// and average of a user-defined segment within the array
// practise with function-based processing of array ranges and pointer 

#include <stdio.h>

double f_sum(int arr[], int *p_start, int *p_end);
int f_min(int arr[], int *p_start, int *p_end);
double f_avg(int arr[], int *p_start, int *p_end, double sum);

int main ()
{
    int arr[100] = {};
    int n,i,start,end;
    int min;
    double sum = 0,average;
    do 
    {
        printf("How many numbers will you enter?\n");
        scanf("%d",&n);
    }
    while (n <= 0 || n > 100);

    printf("Great!\nNow enter the value:");
    for (i = 0; i < n; i++)
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }

    printf("Perfect decide the min and max range\n");
    printf("Min = ");
    scanf("%d",&start); int *p_start = &start;
    printf("Max = "); 
    scanf("%d",&end); int *p_end = &end;

    sum = f_sum(arr,&start,&end);
    min = f_min(arr,&start,&end);
    average = f_avg(arr,&start,&end,sum);

    printf("-- Final output --\n");
    printf("The sum is %.2f\n",sum);
    printf("The min is %d\n",min);
    printf("The average is %.4f\n",average);

    return 0;
}

double f_sum(int arr[], int *p_start, int *p_end)
{
    int counter = *p_start;
    double sum = 0;
    for (; counter <= *p_end; counter++ )
    {
        sum = sum + arr[counter];
    }

    return sum;
}

int f_min(int arr[], int *p_start, int *p_end)
{
    int inizial = *p_start;
    int min = arr[inizial];
    for (; inizial <= *p_end; inizial++)
    {
        if (arr[inizial] < min)
        min = arr[inizial]; 
    }

    return min;
}

double f_avg(int arr[], int *p_start, int *p_end, double sum)
{
    int elements;
    double avg = 0;
    elements = *p_end - *p_start;

    avg = sum/elements;
    return avg;
}
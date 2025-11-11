/*
 * This  program reads a sequence of integers into an array, then calculates
 * the sum, average, maximum, and minimum values. 
 */
#include <stdio.h>
void print(float average, int sum, int max, int min);
int main ()
{
    int counter,max,min,sum;
    float d,average;
    int i = 0;
    int n = 0;
    int arr[100];
    int *p = arr;
    sum = 0;

    do 
    {
        printf("How many number will you enter?\n");
        scanf("%d",&n);
    }
    while (n <= 0);

        for (; i < n; i++)
        {
            printf("Enter a number:");
            scanf("%d",&(*p));
            printf("\n");
            p ++;
        }
    
            max = min = arr[0];
            for (counter = 0; counter < n; counter ++)
            {
                printf("value: %d address:%p\n",arr[counter],&arr[counter]);
                sum = sum+arr[counter];
                if (max < arr[counter]) 
                    {
                        max = arr[counter];
                    }
                if (min > arr[counter]) 
                    {
                        min = arr[counter];
                    }
            }    
        d = n;
        average = sum/d;
        print(average,sum,max,min);
    return 0;
}

void print(float average, int sum, int max, int min)
{
    printf("average= %f\n",average);
    printf("sum = %d\n",sum);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}
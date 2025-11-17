//this program reads temperature stats and calculate differents value using array
#include <stdio.h>
int main ()
{
    int temperatures[5] = {0};
    int i,c = 0,lowest,top;
    float sum,average_t; 

    for (i = 0; i < 5; i++) 
        {
        printf("Enter Temperatures:");
        scanf("%d",&temperatures[i]);
        printf("\n");
        sum = temperatures[i] + sum;
        }
    
    average_t = sum/5;
    

    lowest = temperatures[0];
    top = temperatures[0];
    sum = 0;
    for (i = 0; i < 5; i++)
        {
            if (temperatures[i] < average_t)
                c++;
            if (temperatures[i] > top)
                top = temperatures[i];
            if (temperatures[i] < lowest)
                lowest = temperatures[i];
        }

        printf("=== Result ===\n");
        printf("top = %d\n",top);
        printf("lowest = %d\n",lowest);
        printf("average = %f\n",average_t);
        printf("numbers under average = %d\n",c);
    return 0;
}
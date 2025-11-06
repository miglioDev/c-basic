/*
 * Description: Reads a series of integers and calculates the maximum,
 * minimum, and average value using pointer-based data sharing between
 * functions, to keep improving on pointer and review loop
 */

#include <stdio.h>
void avg_function(int *p,int *p_tot);
int main ()
{
    int counter,i,t_number,max,min,average_total,total;
    float d,average_result;
    max=0;
    counter=0;
    average_total=0;
    i = 0;
    total=0;
    int *p_tot = &total;
    printf("== Welcome == \nHow many numbers will you enter?:\t");
    scanf("%d",&counter);
    d = counter+.0;
    while (i < counter)
    {
        printf("\nNumber:");
        scanf("%d",&t_number);
        int *p= &t_number;
        if (i == 0) {
        max = t_number;
        min = t_number;
        }
            if (t_number > max) 
            {
            max = t_number;
            }
            else if (t_number < min) 
            {
                min = t_number;
            }
        avg_function(p,p_tot);
        i++;
    }
    average_total = total;
    average_result = average_total/d; 

    printf("Result:\n");
    printf("max=%d\tmin=%d",max,min);
    printf("\naverage value =%f",average_result);

    return 0;
}
void avg_function(int *p,int *p_tot)
{
    (*p_tot) = (*p_tot)+(*p);
}
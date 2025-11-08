 /*
 * this program reads a series of integers and calculates the sum,
 * count, and average of even and odd numbers using pointer-based
 * data manipulation between functions. 
 */
 #include <stdio.h>
 void analyze_fun(int *pc_even, int *pc_odd, int *ps_even, int *ps_odd, int *avg_even, int  *avg_odd);
 int main ()
 {
    int x,i,n,is_even,is_odd,counter_even,counter_odd,sum_even,sum_odd,average_even,average_odd;
    counter_even = 0;
    counter_odd = 0;
    sum_even = 0;
    sum_odd= 0;
    average_even = 0;
    average_odd = 0;

    int *p = &x;
    int *pc_even = &counter_even;
    int *pc_odd = &counter_odd;
    int *ps_even = &sum_even;
    int *ps_odd = &sum_odd;
    int *avg_even = &average_even;
    int *avg_odd = &average_odd;

    printf("How many number will you enter? ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter number:");
        scanf("%d",&x);
        is_even = 0;
        is_odd = 0;
        if (x%2 == 0)
            {
                is_even = 1;
            }
            else if (x%2 != 1)
                {
                    is_odd = 1;
                }
        if (is_even)
                {
                    counter_even ++;
                    sum_even = sum_even+x;
                }
                else if (is_odd)
                    {
                        counter_odd ++;
                        sum_odd = sum_odd+x;
                    }
    }

    analyze_fun(pc_even,pc_odd,ps_even,ps_odd,avg_even,avg_odd);

    printf("== output ==\n");
    printf("Total even number: %d\n",(counter_even));
    printf("Total odd number: %d\n",(counter_odd));
    printf("Sum of even number: %d\n",(sum_even));
    printf("Sum of even number: %d\n",(sum_odd));
    printf("Average of even number: %d\n",(average_even));
    printf("Average of odd number: %d\n",(average_odd));
    printf("Last memory address %p\n",(void*)p);

    return 0;
 }
 void analyze_fun(int *pc_even, int *pc_odd, int *ps_even, int *ps_odd, int *avg_even, int  *avg_odd)
 {
    (*avg_even) = (*ps_even)/(*pc_even);
    (*avg_odd) = (*ps_odd)/(*pc_odd);
 }
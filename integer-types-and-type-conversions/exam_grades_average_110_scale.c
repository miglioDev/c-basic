// This program loads a sequence of exam grades with validation, computes the average on a 30-point scale,
// converts it to a 110-point scale, and adjusts the result by adding bonuses for honors (30+).

#include <stdio.h>
#define DIM 6

void load_grades(int vec[DIM]);
float average(int vec[DIM]);

int main ()
{
    float res;
    int vec[DIM];

    load_grades(vec);
    res = average(vec);
    printf("\nFinal average: %0.2f", res);

    return 0;
}

void load_grades(int vec[DIM])
{
    int cond,i;
    do
    {
        cond = 1;
        for(i = 0; i < DIM && cond; i++)
        {
            printf("\nEnter number: ");
            scanf("%d", &vec[i]);
            cond = (vec[i] >= 18 && vec[i] <= 31); 
        }
        if(!cond) 
            printf("Error-- (18-31 range)\n");
    } 
    while (!cond);
}

float average(int vec[DIM])
{
    int i,sum = 0,counter = 0;
    float avg_float,final;
    for(i = 0; i < DIM; i++)
    {
        if(vec[i] == 31) {
            sum = sum+30;
            counter++; }

        else {
            sum = sum+vec[i];}
    }
    avg_float = (float)sum/i;
    final = avg_float * (110.0 / 30.0);
    final = final + (0.25*counter);

    return final;
}
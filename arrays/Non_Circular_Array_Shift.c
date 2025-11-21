//This program ask the user an array and the desired direction of the shift
//display array index and values, then apply a non/circular shift. 
#include <stdio.h>
#define dim 10

char direction(void);
void visualaze_vector(int arr[]);
void right_shift(int arr[]);
void left_shift(int arr[]);

int main ()
{
    int arr[dim];
    int i;
    char shift_type;
    printf("== Welcome ==\n Enter 10 numbers\n");
    for (i = 0; i < dim; i++)
    {
        printf("\nNumber: ");
        scanf("%d",&arr[i]);
    }

    shift_type = direction();
    visualaze_vector(arr);

    if (shift_type == 'R') {
        right_shift(arr); }
        else { 
            left_shift(arr); }

    printf("--\nVector after the shift--\n");
    visualaze_vector(arr);

    return 0; 
}

char direction(void)
{
    char c;
    do
    {
    printf("Enter R or L to decide the shift:\n");
    scanf("%c",&c);
    scanf("%c",&c);
        if ('c' != 'R' && 'c' != 'L') {
           printf("Error - enter a valid type\n"); }
        }
    while((c != 'R') && (c != 'L'));

    return c;
}

void visualaze_vector(int arr[])
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("index = %d\tvalue:%d\n",i,arr[i]);
    }
}

void right_shift(int arr[])
{
    int i;
    for (i = 0; i < dim-1; i++)
    {   
        arr[i] = arr[i+1];
    }
    arr[dim-1] = 0;
}

void left_shift(int arr[])
{
    int i;
    for (i = dim; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = 0;
}
// This program performs circular left or right shifts on a fixed array.
// It includes functions to request a valid shift direction from the user and the number of shift,
#include <stdio.h>
#define dim 5

char shift_fun();
int number_of_shifts();
void rigth_shift_cir(int arr[],int n_times);
void left_shift_cir(int arr[]);
void fun_visual(int arr[]);


int main ()
{
    int n_times,i;
    char s;
    int arr[dim] = {3,4,5,6,7};

    s = shift_fun();

    n_times = number_of_shifts();

    printf("== Before the shift ==\n");
    fun_visual(arr);

    if (s == 'R' || s == 'r') {
        rigth_shift_cir(arr,n_times); }

        else { for (i = 0; i < n_times; i++)
            left_shift_cir(arr); }

    printf("== After the shift ==\n");
    fun_visual(arr);

    return 0;
}

char shift_fun()
{
    char shift;
    int ok = 0;

    do
    {
    printf("\nEnter the desired shift direction (R right or L left):\n");
    scanf("%c",&shift);
    if (shift == 'R' || shift == 'r' || shift == 'L' || shift == 'l') {
        ok = 1; }
        if (ok == 0) {
            printf("Error - enter a valid type of shift\n"); }
    }
    while ( !ok );

    return shift;
}

int number_of_shifts()
{
    int x;
    printf("How many shift do you want?\n");
    scanf("%d",&x);

    return x;
}

void rigth_shift_cir(int arr[],int n_times)
{
    do
    {
        int k,i;
        k = arr[dim-1];
        for (i = dim -1; i > 0; i--) 
        {
            arr[i] = arr[i-1];
        }
        arr[0] = k; 

        n_times --;
    }
    while (n_times > 0);
}

void left_shift_cir(int arr[])
{
    int i,k;
    k = arr[0];
    for(i = 0; i < dim-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[dim-1] = k;
}

void fun_visual(int arr[])
{
    int i;
    for (i  = 0; i < dim; i++)
    {
        printf("index:%d\tvalue:%d\n",i,arr[i]);
    }
}
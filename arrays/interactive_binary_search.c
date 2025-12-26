// Program that performs binary search to guess a number between 1 and 999, 
// practicing binary search logic and user input handling.

#include <stdio.h>
#define dim 1000

int bynary_s(int arr[dim]);
void fill_arr(int arr[dim]);

int main ()
{
    int arr[dim];
    int step;

    printf("Think of one number from 1-999\n");
    
    fill_arr(arr);
    step = bynary_s(arr);

    printf("it took %d calculation",step);

    return 0;
}

void fill_arr(int arr[dim])
{
    int i;
    for(i = 1; i < dim; i++)
    {
        arr[i] = i;
    }
}

int bynary_s(int arr[dim])
{
    int low = arr[1], high = arr[dim-1], mid, counter,result = 0;
    char response;

    printf("Enter H-h or L-l and K if is correct\n");

    for(counter = 0; counter <= 15 && result == 0; counter++)
    {
        mid = (low+high)/2;
        printf("is your number %d? higher or lower?",mid);
        scanf(" %c",&response);
        if(response == 'H' || response == 'h') {
            low = mid+1;}
        
        else if(response == 'L' || response == 'l') {
            high = mid-1;}

        else if(response == 'K' || response == 'k') {
            printf("Great!\n"); result = 1;}
    }   
    return counter;
}
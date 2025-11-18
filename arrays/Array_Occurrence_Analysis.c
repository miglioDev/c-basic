//This program reads a list of integers and performs different analyses
//- checks whether all elements are positive
//- checks whether at least one even number exists
// then searches for the first, last, and total occurrences of a target, no pointer allowed :(

#include <stdio.h>
#define dim 13

int all_pos(int arr[]);
int one_even(int arr[]);
int first_occ(int arr[]);
int number_of_occ(int arr[]);
int last_occ(int arr[]);

int main ()
{
    int i,all_positive,have_one_even,address_first_occ,address_last_occ,n_of_occ;
    int arr[dim] = {};

    printf("Enter 12 numbers:");
    for (i = 0; i < dim-1; i++)
    {
        printf("\nNumber:");
        scanf("%d",&arr[i]);
    }
    i++;
    printf("Great now enter a special number:\n");
    scanf("%d",&arr[i]);

    printf("== result ==\n");

    all_positive = all_pos(arr);
    have_one_even = one_even(arr);
    address_first_occ = first_occ(arr);
    address_last_occ = last_occ(arr);
    n_of_occ =  number_of_occ(arr);

    if (all_positive) {
        printf("The number are all positive\n");}
        else 
            printf("The number are not all positive\n");
    if (have_one_even) {
        printf("There's at least one even\n");}
        else 
            printf("There are no even number");
    if (n_of_occ == 0) {
        printf("There are not accurrency of your number\n");}
        else {  printf("There are %d accurrency\n",n_of_occ);
                printf("The first one is at %d index\n",address_first_occ);
                printf("The last one is at %d index\n",address_last_occ);}

    return 0;
}

int all_pos(int arr[])
{
    int c,positive = 1;
    for (c = 0; c < dim-2; c++)
    {
        if (arr[c] < 0 && positive)
            positive = 0;
    }
    return positive;
}

int one_even(int arr[])
{
    int c,even = 0;
    for (c = 0; c < dim-2; c++)
    {
        if (arr[c]%2 == 0)
            even = 1;
    }
    return even;
}

int first_occ(int arr[])
{
    int c,index = -1;
    for (c = 0; c < dim-2; c++)
    {
        if (arr[c] == arr[dim-1] && index == -1)
            index = c;
    }
    return index;
}

int last_occ(int arr[])
{
    int c,index = -1;
    for (c = 0; c < dim-2; c++)
    {
        if (arr[c] == arr[dim-1]) {
        index = c;}
    }
    return index;
}

int number_of_occ(int arr[])
{
    int counter = 0,i;
    for (i = 0; i < dim-2; i++)
    {
        if (arr[i] == arr[dim-1])
            counter++;
    }
    return counter;
}
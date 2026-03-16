// program that reads multiple people using structs then finds the oldest person (using separated functions)
#include <stdio.h>
#include <stdlib.h>
#define DIM 16

typedef struct{
    char name[DIM];
    char surname[DIM];
    int age;
} personal_info;

int find_oldest(personal_info people[], int n);
void read_personal_info(personal_info *people, int n);

int main ()
{
    int n,oldest;

    printf("\nHow many people?: ");
    scanf("%d",&n);
    personal_info people[n];

    read_personal_info(people, n);
    oldest = find_oldest(people, n);
    printf("The oldest person is %d index",oldest);

    return 0;
}

void read_personal_info(personal_info *people, int n)
{
    int i;

    for(i = 1; i < n; i++)
    {
        printf("\n-- %d Person --",i);

        printf("\nName: ");
        scanf("%s", people[i].name);

        printf("\nSurname: ");
        scanf("%s",people[i].surname);

        printf("\nAge: ");
        scanf("%d",&people[i].age);
    }
}

int find_oldest(personal_info people[], int n)
{
    int i,max_age,index = 0;
    
    max_age = people[0].age;

    for(i = 0; i < n; i++)
    {   
        if(people[i].age > max_age) {
            max_age = people[i].age;
            index = i;
        }
    }

    return index;
}
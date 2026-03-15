// Program that reads and prints multiple people using structs and different functions
// passing structs to functions and pointers to structs 
#include <stdio.h>
#include <stdlib.h>
#define DIM 16

typedef struct {
    char name[DIM];
    char surname[DIM];
    int age;
} personal_info;

void read_person(personal_info *people);
void print_person(personal_info people[], int count);

void read_person(personal_info *people)
{
    printf("\nName: ");
    scanf("%s", people->name);

    printf("\nSurname: ");
    scanf("%s", people->surname);

    printf("\nAge: ");
    scanf("%d", &people->age);
}

void print_person(personal_info people[], int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("\n\nPerson %d",i+1);
        printf("\nName: %s\nSurname: %s\nAge: %d",people[i].name, people[i].surname, people[i].age);
    }
}

int main ()
{
    int i,n;

    printf("How many people will you enter? ");
    scanf("%d",&n);

    personal_info people[n];

    for(i = 0; i < n; i++)
    {
        read_person(&people[i]);
    }

    print_person(people,n);

    return 0;
}
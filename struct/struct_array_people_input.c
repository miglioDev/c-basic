// Program that stores multiple people's information using an array of structs
// Practices struct definition and array indexing  
#include <stdio.h>
#include <stdlib.h>
#define DIM 20

typedef struct {
    char name[DIM];
    char surname[DIM];
    int age;
} personal_info;

int main() {
    int n,i;

    printf("How many people? ");
    scanf("%d", &n);

    personal_info people[n];

    for(i = 0; i < n; i++)
    {
        printf("\nPerson %d",i);
        printf("\nName: ");
        scanf("%s", people[i].name);

        printf("\nSurname: ");
        scanf("%s", people[i].surname);

        printf("\nAge: ");
        scanf("%d", &people[i].age);
    }

    printf("\nPeople Inserted:");
    for(i = 0; i < n; i++)
    {
        printf("\n%s\t%s\t-%d",people[i].name,people[i].surname,people[i].age);
    }

    return 0;
}
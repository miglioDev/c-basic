// Reads a person's basic information using a struct (name, surname, age) 
// then load the struct with scanf
#include <stdio.h>
#include <stdlib.h>
#define DIM 30

struct personal_info {        
    char name[DIM];
    char surname[DIM];
    int age;
};

int main ()
{
    struct personal_info p;

    printf("Enter your info:\n");
    printf("Name: ");
    scanf("%s", p.name);

    printf("\nSurname: ");
    scanf("%s", p.surname);

    printf("\nAge: ");
    scanf("%d", &p.age);

    return 0;
}
// Program that filters adult people from an array of structs and writes them to a file
// practices struct copying, filtering logic, and file I/O
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 16

typedef struct {
    char name[DIM];
    char surname[DIM];
    int age;
} personal_info;

void read_people(int n, personal_info poeple[n]);
int filter_adults(int n, personal_info people[n], personal_info adults[n]);
void print_on_file(int counter, personal_info adults[counter]);

int main ()
{
    int n,counter;

    printf("How many people? ");
    scanf("%d",&n);

    personal_info people[n];
    personal_info adults[n];

    read_people(n,people);
    counter = filter_adults(n,people,adults);
    print_on_file(counter,adults);

    return 0;
}

void read_people(int n, personal_info people[n])
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nName: ");
        scanf(" %s",people[i].name);

        printf("\nSurname: ");
        scanf(" %s",people[i].surname);

        printf("\nAge: ");
        scanf("%d", &people[i].age);
    }
}

int filter_adults(int n, personal_info people[n], personal_info adults[n])
{
    int i,counter = 0;

    for(i = 0; i < n; i++)
    {
        if( people[i].age >= 18) {
            strcpy(adults[counter].name, people[i].name);
            strcpy(adults[counter].surname, people[i].surname);
            adults[counter].age =  people[i].age;

            counter++;
        }
    }

    return counter;
}

void print_on_file(int counter, personal_info adults[counter])
{
    int i;
    FILE *fp;

    fp = fopen("text.txt", "w");

    if (fp == NULL) {
    printf("File error\n");
    return; }

    for(i = 0; i < counter; i++)
    {
        fprintf(fp,"%s\t%s\t%d\n",adults[i].name,adults[i].surname,adults[i].age);
    }

    fclose(fp);
}

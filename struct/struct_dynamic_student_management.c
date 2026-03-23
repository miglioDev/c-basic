// Program that manages a student info using structs and dynamic memory
// Practices dynamic allocation and pointer access on struct
#include <stdio.h>
#include <stdlib.h>
#define DIM 16

typedef struct {
    char name[DIM];
    char surname[DIM];
    float average;
    int *grades;
} Student;

void add_new_student(Student *st);
void print_data(Student *st);

int main()
{
    Student *st = malloc(sizeof(Student));

    if(st == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    add_new_student(st);
    print_data(st);

    free(st->grades);
    free(st);

    return 0;
}

void add_new_student(Student *st)
{
    int i;
    float sum = 0;

    printf("Name: ");
    scanf("%s",st->name);

    printf("Surname: ");
    scanf("%s",st->surname);

    st->grades = malloc(3 * sizeof(int));

    if(st->grades == NULL) {
        printf("memory faile\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 3; i++)
    {
        printf("Enter grade %d: ",i);
        scanf("%d",&st->grades[i]);
        sum = st->grades[i]+sum;
    }

    st->average = sum/3;
}

void print_data(Student *st)
{
    printf("\nName: %s\n",st->name);
    printf("Surname: %s\n",st->surname);

    printf("Grade: ");
        for(int i = 0; i < 3; i++)
        {
            printf("%d\t",st->grades[i]);
        }

    printf("\nAverage: %.2f",st->average);
}
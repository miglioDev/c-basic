// Store student records in an array of structs 
// compute grade averages, and find the student with the highest one
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int grades[5];
    float average;
} Student;

void load_student(int n, Student s_list[n]);

int main()
{
    int n,i,id_best_student;
    float best;

    printf("\nHow many student will you enter? ");
    scanf("%d",&n);

    Student *s_list = malloc(sizeof(Student) * n);
    load_student(n,s_list);

    for(i = 0; i < n; i++)
    {
        if(i == 0) {
            best = s_list[i].average;
            id_best_student = i; }

        if(s_list[i].average > best) {
            best = s_list[i].average;
            id_best_student = i; }
    }

    printf("\n\n=== Overall best student === ");
    printf("\nStudent number: %d",id_best_student);
    printf("\nName: %s\nAverage score: %f",s_list[id_best_student].name,s_list[id_best_student].average);

    free(s_list);
}

void load_student(int n, Student s_list[n])
{
    int i,j,sum;
    float f = 5.0;

    for(i = 0; i < n; i++)
    {
        printf("\n\nStudent: %d\n",i);
        printf("\nEnter name: ");
        scanf("%s",s_list[i].name);

        sum = 0;
        for(j = 0; j < f; j++)
        {
            printf("\nEnter grade n.%d: ",j);
            scanf("%d",&s_list[i].grades[j]);

            sum = sum + s_list[i].grades[j];
        }
        
        s_list[i].average = sum/f;
    }
}
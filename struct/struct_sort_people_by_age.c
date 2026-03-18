// Program that reads, sorts by age, and prints people info using structs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 16

struct personal_info {
    char name[DIM];
    char surname[DIM];
    int age; 
}p_info;

void sort_by_age(int n,struct personal_info p_info[n]);
void enter_data(int n, struct personal_info *p_info);
void print_data(int n,struct personal_info p_info[n]);

int main () {
    int n = 3;
    struct personal_info p_info[n];

    enter_data(n,p_info);
    sort_by_age(n,p_info);
    print_data(n,p_info);

    return 0;
}

void enter_data(int n, struct personal_info *p_info)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nName: ");
        scanf("%s", p_info[i].name);

        printf("Surname: ");
        scanf("%s", p_info[i].surname);

        printf("Age: ");
        scanf("%d", &p_info[i].age);
    }
}

void sort_by_age(int n,struct personal_info p_info[n])
{
    struct personal_info temp;
    int i,j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p_info[j].age > p_info[j+1].age) {
                temp = p_info[j];
                p_info[j] = p_info[j+1];
                p_info[j+1] = temp; }
        }
    }
}

void print_data(int n,struct personal_info p_info[n])
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\n%d) %s\t%s\t%d",i,p_info[i].name,p_info[i].surname,p_info[i].age);
    }
}
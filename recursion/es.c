//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

typedef struct node{
    char name[DIM];
    char surname[DIM];
    struct node *next;
}node;

typedef struct node *LINK;

LINK build_list(int *counter);
void add_one_relative(LINK lis);
void print_list(LINK lis, int *c);

int main ()
{
    int counter;
    printf("\nEnter list dimension: ");
    scanf("%d",&counter);

    LINK head = build_list(&counter);

    printf("\nNow add one more person (relative): ");
    add_one_relative(head);

    counter = 1;
    printf("\n\n=== List ===");
    print_list(head,&counter);

    return 0;
}

LINK new_node() {
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Error: memory fail\n");
        exit(EXIT_FAILURE); }
    return p;
}

LINK build_list(int *counter) {
    LINK p = NULL;

    if(*counter > 0) {
        (*counter)--;
        p = new_node();

        printf("\nName: ");
        scanf("%s",p->name);
        printf("\nSurname: ");
        scanf("%s",p->surname);

        p->next = build_list(counter);
        return p; }

    return p;
}

void add_one_relative(LINK lis)
{
    LINK p = new_node();

    printf("\nName: ");
    scanf("%s",p->name);
    printf("\nSurname: ");
    scanf("%s",p->surname);

    while(strcmp(lis->surname,p->surname) != 0)
    {
        lis = lis->next;
    }

    p->next = lis->next;
    lis->next = p;
}

void print_list(LINK lis, int *c)
{
    if(lis == NULL) return;
    else {
        printf("\n\nPerson: %d",*c);
        printf("\nName: %s",lis->name);
        printf("\nSurname: %s",lis->surname);
        (*c)++;
        print_list(lis->next,c);
    }
}
// Iterative search for the n-th occurrence of a surname in a linked list
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 20

typedef struct node {
    char name[DIM];
    char surname[DIM];
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void load_list(LINK *head);
LINK find_n_occ(char sur[],LINK lis);

int main ()
{
    char surname_find[DIM];
    LINK head = NULL;

    load_list(&head);

    printf("\nNow enter a surname to find 2 occ: ");
    scanf("%s",surname_find);

    LINK res = find_n_occ(surname_find,head);
    if(res == NULL) {
        printf("Not found\n");
        exit(1); }

    printf("\nResult:\n");
    printf("Name: %s\n",res->name);
    printf("Surname: %s\n",res->surname);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));

    if(n == NULL) {
        printf("Error - memory fail\n");
        exit(EXIT_FAILURE); }

    return n;
}

void load_list(LINK *head)
{
    for(int i = 0; i < 5; i++)
    {
        LINK p = new_node();
        printf("\n%d)\n",i);
        printf("Enter name: ");
        scanf("%s",p->name);

        printf("Enter surname: ");
        scanf("%s",p->surname);

        p->next = *head;
        *head = p;
    }
}

LINK find_n_occ(char sur[],LINK lis)
{
    int counter = 0;
    
    while(lis != NULL)
    {
        if(strcmp(lis->surname,sur) == 0) {
            counter++; }
                if(counter == 2) {
                    return lis; }

        lis = lis->next;
    }

    return NULL;
}
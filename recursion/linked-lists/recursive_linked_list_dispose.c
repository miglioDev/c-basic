// recursively deallocate a linked list using a double pointer to update the head
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list(int *dim);
void print_list(LINK lis);
void dispose_list(LINK *lis);

int main ()
{
    srand(time(NULL));
    int dim = 0;

    LINK head = build_list(&dim);

    printf("List:\n");
    print_list(head);

    printf("\nDisposing list...\n");
    dispose_list(&head);
    print_list(head);
    printf("Complete\n");
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

LINK build_list(int *dim)
{
    LINK p;
    if(*dim == 14) return NULL;
    else {
        p = new_node();
        (*dim)++;

        p->data = rand()%100;
        p->next = build_list(dim);
        return p;
    }
}

void print_list(LINK lis)
{
    if(lis == NULL) return;
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next);
    } 
}

void dispose_list(LINK *lis)
{
    LINK p;

    if(*lis == NULL) return;
    else {
        p = *lis;
        *lis = (*lis)->next;
        dispose_list(lis);
        free(p);
    }
}

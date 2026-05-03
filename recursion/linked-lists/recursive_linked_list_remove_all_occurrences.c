// Recursively remove all nodes with a given value from a linked list
// by handling head and then processing internal nodes
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
void del_first_occx(LINK *head, int x);
void remove_node_with_value(LINK lis, int x);

int main ()
{
    srand(time(NULL));
    int x,dim = 0;

    LINK head = build_list(&dim);
    print_list(head);

    printf("\nRemove all node with value: ");
    scanf("%d",&x);

    del_first_occx(&head,x);
    remove_node_with_value(head,x);
    printf("\nUpdated list:\n");
    print_list(head);
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("error memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

LINK build_list(int *dim)
{
    LINK p;
    if(*dim == 16) return NULL;
    else {
        p = new_node();
        (*dim)++;

        p->data = rand()%5;
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

void del_first_occx(LINK *head, int x)
{
    LINK p;
    if(*head != NULL) {
        if((*head)->data == x) {
            p = *head;
            *head = (*head)->next;
            del_first_occx(head,x);
            free(p); 
        }
    }
}

void remove_node_with_value(LINK lis, int x)
{
    LINK p;

    if(lis != NULL) {
        if(lis->next != NULL) {
            if(lis->next->data == x) {
                p = lis->next;
                lis->next = lis->next->next;
                free(p);
                remove_node_with_value(lis,x);
            }
            else {
                remove_node_with_value(lis->next,x);
            }
        }
    }
}
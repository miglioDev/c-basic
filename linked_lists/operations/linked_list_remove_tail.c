// Remove the last node (tail) from a singly linked list, handling both single-node and multi-node cases
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK;
LINK new_node(void);
void push_node(LINK *h);
void print_list(LINK h);
void remove_last_node(LINK *h);

int main()
{
    node *head = NULL;

    for(int i = 0; i < 6; i++)
    {
        push_node(&head);
    }

    print_list(head);
    remove_last_node(&head);

    printf("\nAfter removing:\n");
    print_list(head);

    return 0;
}

LINK new_node(void)
{
    LINK n = malloc(sizeof(*n));
    
    if(n == NULL) {
        printf("Memory fail: new node allocation\n");
        exit(EXIT_FAILURE);
    }

    return n;
}

void push_node(LINK *h)
{
    LINK n_node = new_node();
    n_node->data = rand()%10;

    if(*h == NULL) {
        *h = n_node;
        n_node->next = NULL;
        return; }

    n_node->next = *h;
    *h = n_node;
}

void print_list(LINK h)
{
    LINK q = h;

    while(q != NULL)
    {
        printf("Node -> %d\t", q->data);
        q = q->next;
    }
}

void remove_last_node(LINK *h)
{
    LINK p = *h;

    if(p != NULL) {

        if(p->next == NULL) {
            free(*h);
            *h = NULL; }

        else {
            while(p->next->next != NULL)
            {
                p = p->next;
            }

            free(p->next);
            p->next = NULL;}
    }
}
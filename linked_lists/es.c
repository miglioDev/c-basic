#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void push_node(LINK *head, int x);
void append_node(LINK *head, int x);

int main ()
{
    LINK head = NULL;

    push_node(&head,10);
    push_node(&head,50);
    append_node(&head,20);
    append_node(&head,30);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
    return p;
}

void push_node(LINK *head, int x)
{
    LINK n = new_node();

    n->data = x;
    n->next = *head;
    *head = n;
}

void append_node(LINK *head, int x)
{
    LINK p = new_node();
    p->data = x;
    p->next = NULL;

    if(*head == NULL) {
        *head = p;
        return; }

    LINK current = *head;
    while(current->next != NULL) 
    {
        current = current->next;
    }

    current->next = p;
}
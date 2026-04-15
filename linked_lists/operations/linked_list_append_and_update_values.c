// Create and modify a singly linked list using typedef and helper functions
// my goal here was to go through the linked list, increment the int data of each node by 10 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK; 

LINK f_new_node(void);
void append_node(LINK *h);
void print_list(LINK p);
void incr_value(LINK *h);

int main()
{
    node *head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 12; i++) 
    {
        append_node(&head); 
    }

    print_list(head);
    incr_value(&head);
    print_list(head);

    return 0;
}

LINK f_new_node(void)
{
    LINK n = malloc(sizeof(*n));
    
    if(n == NULL) {
        printf("Error memory fail!\n");
        exit(EXIT_FAILURE); }

    return n;
}

void append_node(LINK *h)
{
    LINK n,q;

    n = f_new_node();
    n->next = NULL;
    n->data = rand()%10;

    if(*h == NULL) {
        *h = n;
        return; }

    q = *h;
    while(q->next != NULL)
    {
        q = q->next;
    }

    q->next = n;
}

void print_list(LINK p)
{
    LINK q = p;

    while(q != NULL)
    {
        printf("node-> %d\t",q->data);
        q = q->next;
    }
}

void incr_value(LINK *h)
{
    printf("\n\n== After value update ==\n");

    LINK q = *h;

    while(q != NULL)
    {
        q->data += 10;
        q = q->next;
    }
}
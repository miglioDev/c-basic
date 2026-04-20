// Implements insertion of a new node at a specific position in a singly linked list
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *head);
void print_list(LINK l);
void add_node_in_position(LINK *head, int n, int x);

int main ()
{
    int value,position;
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 8; i++)
    {
        append_node(&head);
    }

    print_list(head);

    printf("\nAdd extra node in position: ");
    scanf("%d",&position);
    printf("\nWith value: ");
    scanf("%d",&value);

    add_node_in_position(&head,position,value); 
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Error - memory fail");
        exit(EXIT_FAILURE); }
    return n;
}

void append_node(LINK *head)
{
    LINK node = new_node();
    node->data = rand()%10;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
        return; }
    
    else {
        LINK q = *head;
        while(q->next != NULL)
        {
            q = q->next;
        }

        q->next = node; }
}

void print_list(LINK l)
{
    while(l != NULL)
    {
        printf("node-> %d\t",l->data);
        l = l->next;
    }
}

void add_node_in_position(LINK *head, int n, int x)
{
    int i = 0;
    LINK node,q = *head;
    node = new_node();
    node->data = x;

    if(n < 0) {
        printf("invalid position\n");
        exit(1); }

    if(n == 0) {
        node->next = *head;
        *head = node;
        return; }

    while(i < n-1 && q != NULL)
    {
        q = q->next;
        i++;
    }

    if(q == NULL) {
        printf("Error - invalid position");
        free(node);
        exit(2); }

    node->next = q->next;
    q->next = node;
}
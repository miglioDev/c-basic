// reverses a singly linked list in-place by iteratively updating next pointer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

void push_node(LINK *head);
void print_list(LINK lis);
void invert_list(LINK *head);

int main ()
{
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 6; i++)
    {
        push_node(&head);
    }

    print_list(head);
    invert_list(&head);
    print_list(head);

    return 0; 
}

LINK new_node()
{
    LINK node = malloc(sizeof(*node));
    if(node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    return node;
}

void push_node(LINK *head)
{
    LINK n = new_node();

    n->data = rand()%10;
    n->next = *head;
    *head = n;
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("node -> %d\t",lis->data);
        lis = lis->next;
    }
}

void invert_list(LINK *head)
{
    LINK prec,next_n,current;
    current = *head;
    prec = NULL;

    while(current != NULL)
    {
        next_n = current->next;
        current->next = prec;

        prec = current;
        current = next_n;
    }

    *head = prec;

    printf("\nList inverted:\n");
}
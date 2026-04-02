// In this program we have a linked list that uses `push` and `append` with a counter to assign sequential values
// my aim was to demonstrate the difference between `push` and `append` ex. Node data: 2  Node data: 1  Node data: 3
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push_node(struct node **head, int *counter);
void append_node(struct node **head, int *counter);
void print_list(struct node *head);

int main ()
{
    int counter = 0;
    struct node *head = NULL;

    push_node(&head,&counter);
    push_node(&head,&counter);
    append_node(&head,&counter);
    print_list(head);

    return 0;
}

void push_node(struct node **head, int *counter)
{
    (*counter)++;
    struct node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = *counter;

    new_node->next = *head;
    *head = new_node;
}

void append_node(struct node **head, int *counter)
{
    (*counter)++;

    struct node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = *counter;
    new_node->next = NULL;

    if(*head == NULL) {   
        *head = new_node;
        return; }

    struct node *current = *head;
    while(current->next != NULL )
    {
        current = current->next;
    }

    current->next = new_node;
}

void print_list(struct node *head)
{
    struct node *current = head;

    while(current != NULL)
    {
        printf("Node data: %d\t\t", current->data);
        current = current->next;
    }
}
// Implement head insertion and tail append in a singly linked list then print elements
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push_node(struct node **head);
void append_node(struct node **head);
void print_list(struct node *head);

int main()
{
    struct node *head = NULL;

    push_node(&head);
    append_node(&head);
    print_list(head);

    return 0;
}

void push_node(struct node **head)
{
    struct node *new_node = malloc(sizeof(*new_node));

    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = 10;
    new_node->next = *head;
    *head = new_node;
}

void append_node(struct node **head)
{
    struct node *new_node = malloc(sizeof(*new_node));

    new_node->data = 5;
    new_node->next = NULL;

    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    if(*head == NULL) {
        *head = new_node;
        return; }
    
    struct node *current = *head;
    while(current->next != NULL) {
        current = current->next; }

    current->next = new_node;
}

void print_list(struct node *head)
{
    struct node *current = head;

    while(current != NULL)
    {
        printf("Data = %d\t\t",current->data);
        current = current->next;
    }
}
// the goal was to create a singly linked list, insert a node at the head using a double pointer
// practice dynamic memory allocation and pointer 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push_node(struct node **head);

int main ()
{
    struct node *head = NULL;
    push_node(&head);

    free(head);

    return 0;
}

void push_node(struct node **head)
{
    struct node *new_node = malloc(sizeof(struct node));

    if(new_node == NULL) {
        printf("Memory fail");
        exit(EXIT_FAILURE); }
    
    new_node->data = 88;

    new_node->next = *head;
    *head = new_node;
}
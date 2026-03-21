// this program is a simple singly linked list using head insertion that print all elements
// final list head → 20 → 10 → NULL
#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void push_node1(struct node **head);
void push_node2(struct node **head);
void print_list(struct node *head);

int main()
{
    struct node *head = NULL;

    push_node1(&head);
    push_node2(&head);

    print_list(head);

    return 0;
}

void push_node1(struct node **head)
{
    struct node *new_node = malloc(sizeof(struct node));
    
    new_node->data = 10;
    new_node->next = *head;
    *head = new_node;
}

void push_node2(struct node **head)
{
    struct node *new_node = malloc(sizeof(struct node)); 

    new_node->data = 20;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct node *head)
{
    struct node *current = head;

    while(current != NULL) 
    {
        printf("\n%d",current->data); 
        current = current->next;
    }
}
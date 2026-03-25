#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push_node(struct node **head);
void append_node(struct node **head);
void print_list(struct node *head);
void new_node_with_condition(struct node **head, int n, int x);

int main()
{
    struct node *head = NULL;
    int x = 5;
    int n = 19;

    push_node(&head);
    append_node(&head);
    print_list(head);
    new_node_with_condition(&head,n,x);

    printf("\n\nNew list:\n");
    print_list(head);

    return 0;
}

void push_node(struct node **head)
{
    struct node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = 5;

    new_node->next = *head;
    *head = new_node;
}

void append_node(struct node **head)
{
    struct node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = 15;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node; }

    struct node *current = *head;
    while(current->next != NULL)
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
        printf("Node data: %d\t\t",current->data);
        current = current->next;
    }
}

void new_node_with_condition(struct node **head, int n, int x)
{   
    if(*head == NULL) {                      //empty list case
        printf("\nElement not found\n");
        return; }
    
    if((*head)->data == x) {                 //head node case
        struct node *new_node = malloc(sizeof(*new_node));

        if(new_node == NULL) {
            printf("memory fail\n");
            exit(EXIT_FAILURE); }

        new_node->data = n;
        new_node->next = *head;
        *head = new_node;
        return; }

        struct node *current = *head;        
        while(current->next != NULL && current->next->data != x)   //find node before x
        {
            current = current->next;
        }

        if(current->next != NULL)
        {
            struct node *new_node = malloc(sizeof(*new_node));

            new_node->data = n;
            new_node->next = current->next;
            current->next = new_node; }

        else {
            printf("\nElement not found\n"); }    
}
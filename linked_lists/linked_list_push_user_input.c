// This programm creates a list of three nodes, ask the user integer values to store in each node,
// and then iterates through the list to print them  
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push_node(struct node **head,int *counter);
void print_node(struct node *head, int *counter);

int main ()
{
    struct node *head = NULL;
    int counter = 0;

    push_node(&head,&counter);
    push_node(&head,&counter);
    push_node(&head,&counter);

    print_node(head,&counter);
    free(head);

    return 0;
}

void push_node(struct node **head,int *counter)
{
    struct node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail!\n");
        exit(EXIT_FAILURE); }
        
    (*counter)++;

    printf("Enter the value for the node %d: ",*counter);
    scanf("%d",&new_node->data);

    new_node->next = *head;
    *head = new_node;
}

void print_node(struct node *head, int *counter)
{
    struct node *current = head;

    while(current != NULL)
    {
        printf("Node %d ---> data: %d\t",*counter,current->data);
        (*counter)--;
        current = current->next;
    }
}
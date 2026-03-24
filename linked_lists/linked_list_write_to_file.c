// Creates a singly linked list using append, then writes all node values to a file 
// (file I/O + linked list practice)   file ex: node --> 1  node --> 2 ...
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void append_node(struct node **head, int counter);
void print_node_on_file(struct node **head);

int main ()
{
    int i,n,counter = 1;
    struct node *head = NULL;

    printf("How many node? ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        append_node(&head,counter);
        counter++;
    }

    print_node_on_file(&head);

    return 0;
}

void append_node(struct node **head, int counter)
{
    struct node *new_node = malloc(sizeof(*new_node));

    if(new_node == NULL) {
        printf("Error: memory");
        exit(EXIT_FAILURE); }

    new_node->data = counter;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return; }

    struct node *current = *head;
    while(current->next != NULL)
    {
        current = current->next; 
    }
    current->next = new_node;
}

void print_node_on_file(struct node **head)
{
    FILE *fp;
    fp = fopen("text.txt", "w");

    struct node *current = *head;

    while(current != NULL)
    {
        fprintf(fp,"node --> %d  ",current->data);
        current = current->next;
    }

    fclose(fp);
}
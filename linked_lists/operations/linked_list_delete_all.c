// Delete entire singly linked list by visiting and then freeing all nodes 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
 
typedef struct node *LINK;  

void append_node(LINK *h);
void print_list(LINK h);
void delete_list(LINK *lis);

int main ()
{
    node *head = NULL;

    for(int i = 0; i < 8; i++) {
    append_node(&head); }

    print_list(head);

    delete_list(&head);
    print_list(head);

    return 0;
}

void append_node(LINK *h)
{   
    node *new_node = malloc(sizeof(*new_node)); 
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
  
    new_node->data = rand()%10;
    new_node->next = NULL;

    LINK q = *h;

    if(q == NULL) {
        *h = new_node;
        return; }

    while(q->next != NULL) {
        q = q->next; }

    q->next = new_node;
}

void print_list(LINK h)
{
    LINK q = h;

    while(q != NULL)
    {
        printf("node-> %d\t",q->data);
        q = q->next;
    }
}

void delete_list(LINK *head) {
    LINK p;

    while( *head != NULL)
    {
        p = *head;
        *head = p->next;
        free(p);
    }
    
    printf("\nList deleted\n");
}
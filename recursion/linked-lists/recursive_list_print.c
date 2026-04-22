//recursive traversal and print of a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
 
typedef struct node *LINK;  

void append_node(LINK *h);
void printlis_rt(LINK lis);

int main ()
{
    node *head = NULL;

    for(int i = 0; i < 8; i++) 
    {
    append_node(&head); 
    }

    printlis_rt(head);

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

void printlis_rt(LINK lis) {
    if(lis != NULL) {
        printf(">>> %d\t", lis->data);
        printlis_rt(lis->next); }
}
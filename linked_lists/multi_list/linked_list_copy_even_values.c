// Create a new singly linked list containing only even-valued nodes copied from the original list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;
void push_node(LINK *h);
void print_list(LINK h);
LINK copy_even(LINK h);

int main ()
{
    LINK even_list, head = NULL; 
    srand(time(NULL));

    for(int i = 0; i < 12; i++)
    {
        push_node(&head);
    }

    print_list(head);
    even_list = copy_even(head);
    print_list(even_list);   

    return 0;
}

void push_node(LINK *h)
{
    LINK new_node = malloc(sizeof(*new_node)); 
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = rand()%10;
    new_node->next = *h;
    *h = new_node;   
}

void print_list(LINK h)
{
    LINK q = h;

    while(q != NULL)
    {
        printf("Node -> %d\t",q->data);
        q = q->next;
    }
}

LINK copy_even(LINK l)
{ 
    LINK p, HEAD, TAIL;
    HEAD = NULL;

    while(l != NULL)
    {
        if(l->data%2 == 0) {
            
        p = malloc(sizeof(*p));
        if(p == NULL) {
            printf("Error: memory fail\n");
            exit(EXIT_FAILURE); }

            p->data = l->data;
            p->next = NULL; 

            if(HEAD == NULL) {
                HEAD = p;
                TAIL = p; }

            else {
                TAIL->next = p;
                TAIL = p; } 
            }

        l = l->next;
    }

    printf("\n== New list with even only node ==\n");

    return HEAD;
}
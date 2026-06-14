#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();

int main ()
{
    srand(time(NULL));


    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Error: ");
        exit(EXIT_FAILURE); }
    
    return n;
}

void push_node(LINK *head)
{
    LINK p = new_node();
    p->data = rand()%100;
    
    p->next = *head;
    *head = p;
}
// build then recursively traverse a linked list and increment each node's value by 2
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void increment_list(LINK lis);
void print_list(LINK lis);

int main ()
{
    LINK head = build_list();

    printf("List updated: \n");
    increment_list(head);
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));

    if(n == NULL) {
        printf("Memory faile\n");
        exit(EXIT_FAILURE); }
    return n;
}

LINK build_list()
{
    int x;
    LINK p;

    printf("\nEnter node value: ");
    scanf("%d",&x);

    if(x < 0) 
        return NULL;
    else {
        p = new_node();
        p->data = x;
        p->next = build_list();
        return p;
    }
}

void increment_list(LINK lis)
{
    if(lis == NULL) return;
    else {
        lis->data += 2;
        increment_list(lis->next);
    }
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("Node -> %d\t",lis->data);
        lis = lis->next;
    }
}
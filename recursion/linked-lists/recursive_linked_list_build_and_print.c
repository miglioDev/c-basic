// Build a singly linked list recursively from user input until a non-positive value is entered
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node; 

typedef struct node *LINK;

LINK build_list();
void print_list(LINK lis);

int main ()
{
    LINK head = build_list();
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK node = malloc(sizeof(*node));
    if(node == NULL)
    {
        printf("Memory fail\n");
        exit(EXIT_FAILURE);
    }

    return node;
}

LINK build_list()
{
    int x;
    LINK p;
    printf("\nEnter node data: ");
    scanf("%d",&x);

    if(x <= 0) return NULL;
    else 
    {
        p = new_node();
        p->data = x;
        p->next = build_list();
        return p;
    }
}

void print_list(LINK lis)
{
    if(lis == NULL) return;
    else {
        printf("node -> %d\t",lis->data);
        print_list(lis->next); }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct node *LINK;

LINK new_node();
void push_node(LINK *head);
void print_list(LINK lis);

int main ()
{
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 8; i++)
    {
        push_node(&head);
    }

    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
    
    return n;
}

void push_node(LINK *head)
{
    LINK NODE = new_node();

    NODE->data = rand()%10;
    NODE->next = *head;

    *head = NODE;
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("node -> %d\t",lis->data);
        lis = lis->next;
    }
}
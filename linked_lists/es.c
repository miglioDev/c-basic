#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *head);
void print_list(LINK l);

int main ()
{
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 8; i++)
    {
        append_node(&head);
    }

    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Error - memory fail");
        exit(EXIT_FAILURE); }
    return n;
}

void append_node(LINK *head)
{
    LINK node = new_node();
    node->data = rand()%10;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
        return; }
    
    else {
        LINK q = *head;
        while(q->next != NULL)
        {
            q = q->next;
        }

        q->next = node; }
}

void print_list(LINK l)
{
    while(l != NULL)
    {
        printf("node-> %d\t",l->data);
        l = l->next;
    }
}

void workin_fun(LINK *head)
{
    //es.12 core fun
}
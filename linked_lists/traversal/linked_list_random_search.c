// Build a singly linked list with random values (<10) 
// then implement linear search
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *link;

void push_node(node **head);
void print_list(node *head);
link find(link p, int x);

int main ()
{
    int n,x;
    node *head = NULL;
    srand(time(NULL));

    for(n = 0; n < 16; n++) 
    {
        push_node(&head);
    }

    print_list(head);
    link p = head;

    printf("\nEnter a value to find: ");
    scanf("%d",&x);

    link result = find(p,x);
    if(result == NULL) {
        printf("\nNot found"); }
        else {
            printf("\nFound value:\nnode-->data = %d exist!\n",result->data); }

    free(head);

    return 0;
}

void push_node(node **head)
{
    node *new_node = malloc(sizeof(*new_node));
    new_node->data = rand()%10;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return; }

    new_node->next = *head;
    *head = new_node;
}

void print_list(node *head)
{
    int i = 1;
    node *current = head;

    while(current != NULL)
    {
        printf("Node %d data--> %d\n",i,current->data);
        current = current->next;
        i++;
    }
}

link find(link p, int x)
{
    while(p != NULL)
    {
        if(p->data == x) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}
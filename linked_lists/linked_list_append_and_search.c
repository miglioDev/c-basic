// Append nodes with random values to a singly linked list 
// then and perform linear search, showing the process
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef node *LINK;

void append_node(node **head, int *counter);
LINK find_value(LINK p, int x);

int main ()
{
    node *head = NULL;
    srand(time(NULL));

    int x,counter = 1;
    for(; counter < 15;) 
    {
        append_node(&head,&counter);
    }

    printf("Pick a number to search: ");
    scanf("%d",&x);
    LINK p = head;
    LINK result = find_value(p,x);

    if(result == NULL) {
        printf("Value not found!\n"); }
    else {
        printf("Value %d found in the node list!\n",result->data); }
    
    return 0;
}

void append_node(node **head, int *counter)
{
    node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = rand()%10;
    new_node->next = NULL;
    (*counter)++;

    if(*head == NULL) {
        *head = new_node;
        return; }

    node *current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;    
}

LINK find_value(LINK p, int x)
{
    int c = 1;
    while(p != NULL)
    {
        printf("%d/15 - node data --> %d\n",c,p->data);
        c++;

        if(p->data == x) {
            return p; }
        
        p = p->next;
    }

    return NULL;
}
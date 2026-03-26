// Find the node at a given position in a singly linked list
// practice with position tracking and pointer return + use of typedef
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *link;

void push_node(node **head,int *n);
link find_node(int x, link p);

int main()
{
    int n = 1, c = 0,x;
    node *head = NULL;

    while(c < 8) {
    push_node(&head,&n); 
    c++; }

    link p = head;
    printf("What position do you want to find? ");
    scanf("%d", &x);

    link result = find_node(x,p);
    if(result == 0) {
    printf("Not found\n"); }
        else {
          printf("\n\nValue at position %d: Data: %d",x,result->data); }
    
    return 0;
}

void push_node(node **head, int *n)
{
    node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("memory faile\n");
        exit(EXIT_FAILURE); }

    new_node->data = *n;
    (*n)++;

    new_node->next = *head;
    *head = new_node;
}

link find_node(int x, link p)
{
    int position = 1;

    while(position < x && p != NULL)
    {
        p = p->next;
        position++;
    }

    return p; 
}
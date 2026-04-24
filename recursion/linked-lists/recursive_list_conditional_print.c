// Recursive traversal of linked list with conditional printing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

void push_node(LINK *head);
LINK new_node();
void print_recursive(LINK lis);
void r_print_cond(LINK lis, int c);

int main ()
{
    int c,i;

    LINK head = NULL;
    srand(time(NULL));

    for(i = 0; i < 14; i++) {
        push_node(&head); }

    print_recursive(head);

    printf("\nEnter condintion: ");
    scanf("%d",&c);
    printf("\n");
    r_print_cond(head,c);

    return 0;
}

LINK new_node()
{
    LINK node = malloc(sizeof(*node));
    if(node == NULL) {
        printf("Error: memory ");
        exit(EXIT_FAILURE); }

    return node;
}

void push_node(LINK *head)
{
    LINK n = new_node();
    n->data = rand()%10;

    if(head == NULL) {
        *head = n;
        n->next = NULL;
        return; }

    n->next = *head;
    *head = n;
}

void print_recursive(LINK lis)
{
    if (lis != NULL) {
        printf("%d >>\t",lis->data);
        print_recursive(lis->next); }
}

void r_print_cond(LINK lis, int c)
{
    if(lis == NULL) return;

    if (c != 0 && lis->data%c == 0) {
        printf("%d >>\t",lis->data); }

    r_print_cond(lis->next,c);
}
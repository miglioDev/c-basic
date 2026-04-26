// recursive sum of all nodes in a singly linked list using accumulator pointer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void push_node(LINK *head);
void print_list(LINK lis);
int sum_lis(LINK lis, int *acc);

int main ()
{
    int res = 0;
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 8; i++) 
    {
        push_node(&head);
    }

    print_list(head);
    sum_lis(head,&res);
    printf("\nSum: %d",res);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Error -");
        exit(EXIT_FAILURE); }

    return p;
}

void push_node(LINK *head)
{
    LINK n = new_node();

    n->data = rand()%10;
    n->next = *head;
    *head = n;
}

void print_list(LINK lis)
{
    if(lis == NULL) {
    return; }
        else {
            printf("node -> %d\t",lis->data);
            print_list(lis->next); }
}

int sum_lis(LINK lis, int *acc)
{
    if(lis == NULL) 
        return *acc;

    else {
        *acc = (*acc) + lis->data; 
        return sum_lis(lis->next, acc); }
}
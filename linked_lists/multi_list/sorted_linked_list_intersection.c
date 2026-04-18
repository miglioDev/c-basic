// builds two sorted linked lists with random values then computes their intersection 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct node *LINK;

LINK new_node();
void push_node_sorted(LINK *head);
void print_list(LINK lis);
LINK list_intersection(LINK l1, LINK l2);

int main ()
{
    LINK head1 = NULL;
    LINK head2 = NULL;
    srand(time(NULL));

    for(int i = 0; i < 12; i++)
    {
        push_node_sorted(&head1);
    }

    for(int i = 0; i < 10; i++)
    {
        push_node_sorted(&head2);
    }

    printf("\nFirst list:\n");
    print_list(head1);
    printf("\nSecond list:\n");
    print_list(head2);

    LINK head3 = list_intersection(head1,head2);
    printf("\nIntersection List:\n");
    print_list(head3);

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

void push_node_sorted(LINK *head)
{
    LINK n = new_node();
    n->data = rand()%10;
    n->next = *head;

    if (*head == NULL || n->data < (*head)->data) {
        n->next = *head;
        *head = n;
        return;
    }

    LINK curr = *head;
    while (curr->next != NULL && curr->next->data < n->data) {
        curr = curr->next;
    }

    n->next = curr->next;
    curr->next = n;
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("node -> %d\t",lis->data);
        lis = lis->next;
    }
}

LINK list_intersection(LINK l1, LINK l2)
{
    LINK head,tail;
    head = NULL;
    tail = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data == l2->data) {
            LINK n = new_node();
            n->data = l1->data;
            n->next = NULL;

            if(head == NULL) {
            head = n;
            tail = n; }            
                else {
                tail->next = n;
                tail = n; }

            l1 = l1->next;
            l2 = l2->next; }

        else {
            if(l1->data > l2->data) {
            l1 = l1->next; }
                else 
                l2 = l2->next; }
    }

    return head;
}
// Build a third linked list containing sums of corresponding nodes that exceed a threshold k,
// including excess elements from the longer list
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
LINK build_list_sum_k(LINK lis1, LINK lis2, int k);

int main ()
{
    int i,k;
    srand(time(NULL));

    LINK head1 = NULL;
    LINK head2 = NULL;

    for(i = 0; i < 10; i++)
    {
        push_node(&head1);
    }

    for(i = 0; i < 7; i++)
    {
        push_node(&head2);
    }

    printf("\nList 1:\n");
    print_list(head1);
    printf("\nList 2:\n");
    print_list(head2);

    printf("\nEnter a number k: ");
    scanf("%d",&k);

    LINK head3 = build_list_sum_k(head1,head2,k);

    printf("\n\n3 list with sum and greater than k\n");
    print_list(head3);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Error: ");
        exit(EXIT_FAILURE); }
    
    return n;
}

void push_node(LINK *head)
{
    LINK p = new_node();
    p->data = rand()%10;
    
    p->next = *head;
    *head = p;
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("%d -> ",lis->data);
        lis = lis->next;
    }

    printf("NULL");
}

LINK build_list_sum_k(LINK lis1, LINK lis2, int k)
{
    int t;
    LINK head, tail, p;
    head = NULL;
    tail = NULL;

    while(lis1 != NULL && lis2 != NULL)
    {
        t = lis1->data + lis2->data;
        if(t > k) {
            p = new_node();
            p->data = t;
            p->next = NULL;

            if(head == NULL) {
                head = p;
                tail = p; }
            else {
                tail->next = p;
                tail = p; }
        }

        lis1 = lis1->next;
        lis2 = lis2->next;
    }

    while(lis1 != NULL) {

        t = lis1->data;

        if(t > k) {
            p = new_node();
            p->data = lis1->data;
            p->next = NULL;

            if(head == NULL) {
                head = p;
                tail = p; }
            else {
                tail->next = p;
                tail = p;
            }
        }
        lis1 = lis1->next; }

    while(lis2 != NULL) {

        t = lis2->data;

        if(t > k) {
            p = new_node();
            p->data = lis2->data;
            p->next = NULL;

            if(head == NULL) {
                head = p;
                tail = p; }
            else {
                tail->next = p;
                tail = p;
            }
        }
        lis2 = lis2->next; }

    return head;
}
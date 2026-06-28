// Copies the nodes between positions n and m (inclusive) from a linked list into a new list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void push_node(LINK *lis, int x);
void append_node(LINK *lis_head, int x);
void print_list(LINK lis);
LINK copy_from_n_to_m(LINK lis, int n, int m);

int main()
{
    int i,dim,x,n,m;
    LINK head_lis1 = NULL;
    LINK head_lis2 = NULL;
    srand(time(NULL));

    printf("Enter lis1 dimension: ");
    scanf("%d",&dim);

    for(i = 0; i < dim; i++)
    {
        x = rand()%100;
        push_node(&head_lis1,x);
    }

    printf("\nOriginal List:\n");
    print_list(head_lis1);

    printf("\nNow enter two number n and m: ");
    scanf("%d %d",&n,&m);

    head_lis2 = copy_from_n_to_m(head_lis1,n,m);
    printf("\nElements copied list:\n");
    print_list(head_lis2);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("Error: memory allocation failed\n");
        exit(EXIT_FAILURE); }
    return n;
}

void push_node(LINK *lis, int x)
{
    LINK p = new_node();
    p->data = x;
    p->next = *lis;
    *lis = p;
}

void append_node(LINK *lis_head, int x)
{
    LINK q,p = new_node();
    p->data = x;
    p->next = NULL;

    q = *lis_head;

    if(q == NULL) {
        *lis_head = p;
        return; 
    }

    else {
        while(q->next != NULL)
        {
            q = q->next;
        }

        q->next = p;
    }
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("%d ->",lis->data);
        lis = lis->next;
    }
    printf(" NULL\n");
}

LINK copy_from_n_to_m(LINK lis, int n, int m)
{
    LINK head,tail,p;
    head = NULL;
    tail = NULL;
    int i;

    for(i = 1; i < n && lis != NULL; i++)
    {
        lis = lis->next;
    }

    if(lis == NULL) {
        return NULL; }

    while(lis != NULL && n <= m)
    {
        p = new_node();
        p->data = lis->data;
        p->next = NULL;

        if(head == NULL) {
            head = p;
            tail = p; }
        else {
            tail->next = p;
            tail = p;
        }

        lis = lis->next;
        n++;
    }

    return head;
}
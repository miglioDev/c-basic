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

int main()
{
    int i,n,x;
    LINK head_lis1 = NULL;
    LINK head_lis2 = NULL;
    srand(time(NULL));

    printf("Enter lis1 dimension: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        x = rand()%100;
        push_node(&head_lis1,x);
    }

    printf("\nOriginal List:\n");
    print_list(head_lis1);

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
    printf("NULL\n");
}

LINK copy_from_n_to_m()
{
    //given two number n and m copy the elements from n to m in the original list in a new list
}
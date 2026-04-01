// compute sliding window sums of size k over a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
 
typedef struct node *LINK;  

void push_node(LINK *h);
void print_list(LINK h);
void sum_window(LINK h, int n);

int main()
{
    int i,n;
    node *head = NULL;

    for(i = 0; i < 10; i++)
    {
        push_node(&head);
    }
    print_list(head);

    printf("\nEnter window value: ");
    scanf("%d",&n);

    sum_window(head,n);

    return 0;
}

void push_node(LINK *h)
{
    node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = rand()%10;
    new_node->next = *h;
    *h = new_node;
}

void print_list(LINK h)
{
    LINK q = h;

    while(q != NULL) 
    {
        printf("Node-> %d\t",q->data);
        q = q->next;
    }
}

void sum_window(LINK h, int n)
{
    if(n <= 0) return;

    int count,sum;
    LINK start = h;

    while(start != NULL) 
    {
        sum = 0;
        count = 0;

        LINK q = start;

        for(; count < n && q != NULL; count ++)
        {
            sum = q->data+sum;
            q = q->next;
        }
        start = start->next;

        printf("\nGroup Sum = %d", sum);
    }
}
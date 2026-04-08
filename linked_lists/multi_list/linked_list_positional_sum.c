// Create a new list by summing corresponding nodes of two singly linked lists

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void positional_sum(LINK lis1, LINK lis2, LINK *h);
void push_node(LINK *h);
void print_list(LINK h);

int main ()
{
    int i;
    LINK lis1 = NULL;
    LINK lis2 = NULL;
    LINK lis3 = NULL;

    for(i = 0; i < 6; i++)
    {
        push_node(&lis1);
    }

    for(i = 0; i < 6; i++)
    {
        push_node(&lis2);
    }

    print_list(lis1);
    print_list(lis2);

    positional_sum(lis1, lis2, &lis3);

    printf("List sum: \n");
    print_list(lis3);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));

    return n;
}

void push_node(LINK *h)
{
    LINK n = new_node();

    n->next = *h;
    n->data = rand()%10;
    *h = n;
}

void print_list(LINK h)
{
    while( h != NULL)
    {
        printf("node-> %d\t", h->data);
        h = h->next;
    }
    printf("\n");
}

void positional_sum(LINK lis1, LINK lis2, LINK *h)
{
    while((lis1 != NULL) && (lis2 != NULL))
    {
        LINK list_sum = malloc(sizeof(*list_sum));
        if(list_sum == NULL) {
            printf("Memory fail\n");
            exit(EXIT_FAILURE); }
            
        list_sum->data = (lis1->data) + (lis2->data); 
        list_sum->next = NULL;

        if(*h == NULL) {
            *h = list_sum; }
            else {
                LINK q = *h;
                while( q->next != NULL )
                {
                    q = q->next;
                }
                q->next = list_sum;
            }

        lis1 = lis1->next;
        lis2 = lis2->next;
    }
}
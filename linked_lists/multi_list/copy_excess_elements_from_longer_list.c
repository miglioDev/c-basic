// Compare two linked lists and build a third list containing only the excess elements of the longer list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void push_node(LINK *head, int x);
void append_node(LINK *head, int x);
void print_list(LINK lis);
LINK copy_excess_elements(LINK lis1, LINK lis2);

int main ()
{
    int i;
    LINK head_odd = NULL;
    LINK head_even = NULL;

    for(i = 0; i < 8; i+=2)
    {
        push_node(&head_even,i);
    }

    for(i = 1; i < 16; i+= 2)
    {
        append_node(&head_odd,i);
    }

    printf("List one:\n");
    print_list(head_even);
    printf("List two:\n");
    print_list(head_odd);

    LINK lis3 = copy_excess_elements(head_even,head_odd);
    printf("\n\nList 3 - excess elements copied -\n");
    print_list(lis3);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
    return p;
}

void push_node(LINK *lis, int x)
{
    LINK n;
    
    n = new_node();
    n->data = x;

    n->next = *lis;
    *lis = n;
}

void append_node(LINK *head, int x)
{
    LINK p = new_node();
    p->data = x;
    p->next = NULL;

    if(*head == NULL) {
        *head = p;
        return; }

    LINK current = *head;
    while(current->next != NULL) 
    {
        current = current->next;
    }

    current->next = p;
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("%d -> ",lis->data);
        lis = lis->next;
    }
    printf("NULL\n");
}

LINK copy_excess_elements(LINK lis1, LINK lis2)
{
    LINK new_list = NULL;
    
    while(lis1 != NULL && lis2 != NULL)
    {
        lis1 = lis1->next;
        lis2 = lis2->next;
    }

    if(lis1 != NULL) 
    {
        while(lis1 != NULL)
        {
            append_node(&new_list,lis1->data);
            lis1 = lis1->next;
        } 
    }
    else {
        while(lis2 != NULL)
        {
            append_node(&new_list,lis2->data);
            lis2 = lis2->next;
        }
    }

    return new_list;
}
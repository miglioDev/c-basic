// creates a filtered copy of a singly linked list containing only:
// nodes with values greater than or equal to a given threshold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *head);
void print_list(LINK lis);
LINK filter_list(LINK lis, int x);

int main ()
{
    int x;
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        append_node(&head);
    }

    print_list(head);

    printf("\nFilter new list with number >= to : ");
    scanf("%d",&x);

    LINK lis2 = filter_list(head,x);
    print_list(lis2);

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

void append_node(LINK *head)
{
    LINK q,node;

    node = new_node(); 
    node->data = rand()%10;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
        return; }

    q = *head;
    while(q->next != NULL)
    {
        q = q->next;
    }

    q->next = node;
}

void print_list(LINK lis)
{
    printf("\nList:\n");

    while(lis != NULL)
    {
        printf("node -> %d\t",lis->data);
        lis = lis->next;
    }
}

LINK filter_list(LINK lis, int x)
{
    LINK p,tail,head2 = NULL;

    while(lis != NULL)
    {   
        if(lis->data >= x) {
            p = new_node();
            p->data = lis->data;
            p->next = NULL; 
            
                if(head2 == NULL) {
                    head2 = p;
                    tail = p; }
                    
                else {
                        tail->next = p;
                        tail = p; }
            }

        lis = lis->next;
    }

    return head2;
}
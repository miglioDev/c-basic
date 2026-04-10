#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;
void push_node(LINK *h);
void print_list(LINK h);
void remove_odd(LINK *h);

int main ()
{
    LINK head = NULL; 
    srand(time(NULL));

    for(int i = 0; i < 12; i++)
    {
        push_node(&head);
    }

    print_list(head);
    remove_odd(&head);
    print_list(head);   

    return 0;
}

void push_node(LINK *h)
{
    LINK new_node = malloc(sizeof(*new_node)); 
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
        printf("Node -> %d\t",q->data);
        q = q->next;
    }
}

void remove_odd(LINK *h)
{ 
    LINK q, p, prev;
    q = *h;
    prev = NULL;

    while(q != NULL)
    {
        if(q->data%2 == 1) {
         
            if(prev == NULL) {
            p = q;
            q = q->next;
            free(p); } 
    
            else (q->data%2 == 1) {
                //find precedent and remove
                p = q;
                q = q->next;
                free(p); }
            }

        else {
            q = q->next; }
    }

    printf("\n== odd removed ==\n");
}
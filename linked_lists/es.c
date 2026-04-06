//es.
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
 
typedef struct node *LINK;  

void append_node(LINK *h);
void print_list(LINK h);
void remove_first_node(LINK *h);

int main ()
{
    node *head = NULL;

    for(int i = 0; i < 8; i++) {
    append_node(&head); }

    print_list(head);

    remove_first_node(&head);
    print_list(head);

    return 0;
}

void append_node(LINK *h)
{   
    node *new_node = malloc(sizeof(*new_node)); 
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
  
    new_node->data = rand()%10;
    new_node->next = NULL;

    LINK q = *h;

    if(q == NULL) {
        *h = new_node;
        return; }

    while(q->next != NULL) {
        q = q->next; }

    q->next = new_node;
}

void print_list(LINK h)
{
    LINK q = h;

    while(q != NULL)
    {
        printf("node-> %d\t",q->data);
        q = q->next;
    }
}

//add find prec

void removex(LINK *lis, int x) {
    LINK p, q;

    if (*lis != NULL) {

        if ((*lis)->data == x) {
            p = *lis;
            *lis = (*lis)->next;
            free(p);
        } 
        else {

            p = findpred(x, *lis);

            if (p != NULL) {
                q = p->next;             
                p->next = q->next;       
                free(q);                 
            }
        }
    }
}
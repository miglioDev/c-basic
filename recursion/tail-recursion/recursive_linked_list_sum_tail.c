// recursively build a new linked list as the element-wise sum of two lists using tail insertion
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list();
void print_list(LINK lis);
void build_sum_list_recursive_tail(LINK lis1, LINK lis2, LINK *head, LINK *tail);

int main ()
{
    printf("List one\n");
    LINK lis1 = build_list();
    printf("List two:\n");
    LINK lis2 = build_list();
    LINK head = NULL;
    LINK tail = NULL;

    build_sum_list_recursive_tail(lis1,lis2,&head,&tail);
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Error: memory fail\n");
        exit(EXIT_FAILURE); }
    return p;
}

LINK build_list()
{
    int x;
    LINK p;

    printf("\nEnter node value: ");
    scanf("%d",&x);

    if(x < 0) return NULL;
    else {
        p = new_node();
        p->data = x;
        p->next = build_list(); 
        return p; }
}

void print_list(LINK lis)
{
    while(lis != NULL)
    {
        printf("%d ->\t",lis->data);
        lis = lis->next;
    }
}

void build_sum_list_recursive_tail(LINK lis1, LINK lis2, LINK *head, LINK *tail)
{
    LINK p;

    if((lis1 == NULL) && (lis2 == NULL)) return;

    else if((lis1 != NULL) && (lis2 == NULL))
    {
        p = new_node();
        p->data = lis1->data;
        p->next = NULL;

        if(*head == NULL) {
            *head = p;
            *tail = p; }
        else {
            (*tail)->next = p;
            *tail = p;
        }

        build_sum_list_recursive_tail(lis1->next,lis2,head,tail);
    }
     
    else if((lis1 == NULL) && (lis2 != NULL)) 
    {
        p = new_node();
        p->data = lis2->data;
        p->next = NULL;

        if(*head == NULL) {
            *head = p;
            *tail = p; }
        else {
            (*tail)->next = p;
            *tail = p;
        }

        build_sum_list_recursive_tail(lis1,lis2->next,head,tail);
    }

    else {
        p = new_node();
        p->data = lis1->data + lis2->data;
        p->next = NULL;

        if(*head == NULL) {
            *head = p;
            *tail = p; }
        else {
            (*tail)->next = p;
            *tail = p;
        } 

        build_sum_list_recursive_tail(lis1->next,lis2->next,head,tail);
    }
}
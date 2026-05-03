// Recursively insert a new node after every occurrence of a target value in a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list();
void print_list(LINK lis);
void inser_after(LINK lis, int x, int y);

int main ()
{
    int x,y;
    LINK head = build_list();

    printf("List:\n");
    print_list(head);

    printf("\n\nEnter New Node value: ");
    scanf("%d",&x);
    printf("\nAfter all node with value: ");
    scanf("%d",&y);

    inser_after(head,x,y);
    printf("List:\n");
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
    return  p;
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
    if(lis == NULL) {
        printf("NULL");
        return;}
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next); }
}

void inser_after(LINK lis, int x, int y)
{
    if(lis == NULL) return;
    LINK p;

    if(lis->data != y) inser_after(lis->next,x,y);
    else {
        p = new_node();
        p->data = x;
        p->next = lis->next;
        lis->next = p;

        inser_after(lis->next,x,y);
    }
}
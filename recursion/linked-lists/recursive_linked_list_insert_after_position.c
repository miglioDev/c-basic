// recursively insert a node after a given position in a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list();
void print_list(LINK lis);
void add_node_after_posn(LINK lis, int x, int pos, int *counter);

int main ()
{
    int x,pos;

    LINK head = build_list();
    print_list(head);

    printf("\nEnter extra node value: ");
    scanf("%d",&x);
    printf("Enter after what position extra node must be: ");
    scanf("%d",&pos);

    int counter = 0;
    add_node_after_posn(head,x,pos,&counter);
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));

    if(n == NULL) {
        printf("Error: memory fail");
        exit(EXIT_FAILURE); }
    return n;
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
    
    return p;
}

void print_list(LINK lis)
{
    if(lis == NULL) {
        printf("NULL\n");
        return; }
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next); }
}

void add_node_after_posn(LINK lis, int x, int pos, int *counter)
{
    LINK p;

    if(lis == NULL) return;

    if(*counter < pos) {
        (*counter)++;
        add_node_after_posn(lis->next,x,pos,counter); }
    else {
        p = new_node();
        p->data = x;
        p->next = lis->next;
        lis->next = p;
    }
}
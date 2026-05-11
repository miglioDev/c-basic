// recursively build a linked list then print it in reverse order without modifying node links
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list();
void print_list(LINK lis);
void print_invert_list(LINK lis);

int main ()
{
    LINK head = build_list();

    printf("List:\n");
    print_list(head);

    printf("\nList (inverted):\n");
    print_invert_list(head);
    printf("NULL\n");
    
    return 0;
}

LINK new_node()
{
    LINK p = malloc(sizeof(*p));
    if(p == NULL) {
        printf("Memory allocation fail\n");
        exit(EXIT_FAILURE); }

    return p;
}

LINK build_list()
{
    LINK p;
    int x;

    printf("Enter new node value: ");
    scanf("%d",&x);

    if(x >= 0) {
        p = new_node();
        p->data = x;
        p->next = build_list();
        return p; }
    else 
        return NULL;
}

void print_list(LINK lis)
{
    if(lis == NULL) {
        printf("NULL");
        return; }
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next); }
}

void print_invert_list(LINK lis)
{
    if(lis == NULL) {
        return; }
    
    print_invert_list(lis->next); 
    printf("%d ->\t",lis->data);   
}
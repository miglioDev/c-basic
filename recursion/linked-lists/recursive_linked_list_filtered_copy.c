// Recursively build a linked list from user input and create a filtered copy including only values >= y
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
LINK dup_cond(LINK lis, int y);

int main()
{
    int y;
    srand(time(NULL));

    LINK head = build_list();
    print_list(head);

    printf("\nEnter value for dup-list: ");
    scanf("%d",&y);

    LINK head_list2 = dup_cond(head,y);
    print_list(head_list2);

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

LINK build_list()
{
    int x;
    LINK n;

    printf("\nEnter node value: ");
    scanf("%d",&x);

    if(x >= 0)
    {
        n = new_node();
        n->data = x;
        n->next = build_list();
        return n; }
    else 
        return NULL;
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

LINK dup_cond(LINK lis, int y)
{
    LINK p;
    if(lis == NULL) return NULL;
    else {
        if(lis->data >= y) {
        p = new_node();
        p->data = lis->data;
        p->next = dup_cond(lis->next,y);
        return p; }
        
        else {
            return dup_cond(lis->next,y);}
    }
}
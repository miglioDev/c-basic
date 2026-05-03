// recursively insert a new node before the first occurrence of a target value in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list(int *dim);
void print_list(LINK lis);
void ins_before_focc(LINK lis, int x, int y);

int main ()
{
    srand(time(NULL));
    int x,y,dim = 0;

    LINK head = build_list(&dim); 

    printf("List:\n");
    print_list(head);

    printf("\nEnter new node value: ");
    scanf("%d",&x);

    printf("\nAdd before the first node with value (excluding the head): ");
    scanf("%d",&y);

    ins_before_focc(head,x,y);
    print_list(head);

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

LINK build_list(int *dim)
{
    LINK n;
    if(*dim == 10) return NULL;
    else { 
        (*dim)++;
        n = new_node();
        n->data = rand()%10;
        n->next = build_list(dim);
        return n;
    }

    return n;
}

void print_list(LINK lis)
{
    if(lis == NULL) return;
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next); }
}

void ins_before_focc(LINK lis, int x, int y)
{
    LINK n;
    if (lis == NULL || lis->next == NULL) return;

    if(lis->next->data != y) 
        ins_before_focc(lis->next, x, y);
    else {
        n = new_node();
        n->data = x;

        n->next = lis->next;
        lis->next = n;
        return;
    }
}
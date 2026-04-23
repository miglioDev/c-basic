// recursive sum of first n nodes in a singly linked list 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;
 
typedef struct node *LINK;  

void append_node(LINK *h);
void print_list(LINK lis);
int sum_n_rt(LINK lis, int l, int pos);

int main ()
{
    int pos,res,l;
    node *head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 10; i++) 
    {
    append_node(&head); 
    }

    print_list(head);

    pos = 1;
    res = 0;
    printf("\nNumber of nodes: ");
    scanf("%d",&l);

    res = sum_n_rt(head,l,pos);
    printf("\nResult = %d",res);

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

void print_list(LINK lis)
{
    while(lis != NULL) {
        printf("%d >>\t",lis->data);
        lis = lis->next; }
}

int sum_n_rt(LINK lis, int l, int pos) {
    if(lis == NULL) { return(0); }
    else if(pos <= l) {
        return(lis->data + sum_n_rt(lis->next,l, pos+1)); }
        else return (0);
}


// this program removes all occurrences of a given value from a singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

void push_node(LINK *HEAD);
void print_list(LINK lis);
LINK find_prec(LINK lis, int x);
void remove_all_occ(LINK *head, int x);

int main ()
{
    int x;
    LINK head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 12; i++)
    {
        push_node(&head);
    }

    print_list(head);

    printf("\nEnter an integer from which to remove all occurrences: ");
    scanf("%d", &x);

    remove_all_occ(&head,x);
    print_list(head);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));
    if(n == NULL) {
        printf("error - memory fail\n");
        exit(EXIT_FAILURE); }

    return n;
}

void push_node(LINK *HEAD)
{
    LINK n = new_node();

    n->data = rand()%10;
    n->next = *HEAD;
    *HEAD = n;
}

void print_list(LINK lis)
{
    printf("List:\n");

    while(lis != NULL)
    {
        printf("Node -> %d\t",lis->data);
        lis = lis->next;
    }
}

LINK find_prec(LINK lis, int x)
{
    int flag = 0;

    while(lis->next != NULL && !flag)
    {
        if(lis->next->data == x) {
            flag = 1;
            return lis; }

        lis = lis->next;
    }

    return NULL;
}

void remove_all_occ(LINK *head, int x)
{
    LINK q, p;

    while(*head != NULL && (*head)->data == x) {
        p = *head;
        *head = (*head)->next;
        free(p);
    }

    q = *head;
    while(q != NULL)
    {
            p = find_prec(*head,x);

            if(p == NULL) {
            break; }
                else {
                    LINK target = p->next;
                    p->next = target->next;
                    free(target); }
        }

        q = *head;
}
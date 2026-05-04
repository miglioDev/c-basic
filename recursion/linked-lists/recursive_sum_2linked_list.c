// Recursively build a new linked list as the element-wise sum of two lists
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct node *LINK;

LINK build_list();
LINK build_sum_list(LINK lis1, LINK lis2);
void print_list(LINK lis);

int main ()
{
    LINK head1 = build_list();
    LINK head2 = build_list();

    LINK head_sumlis = build_sum_list(head1,head2);

    printf("\nSum list: \n");
    print_list(head_sumlis);

    return 0;
}

LINK new_node()
{
    LINK n = malloc(sizeof(*n));

    if(n == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }
    return n;
}

LINK build_list()
{
    int x;
    LINK p;

    printf("Enter node value: ");
    scanf("%d",&x);

    if(x < 0) return NULL;
    else {
        p = new_node();
        p->data = x;
        p->next = build_list();
        return p;
    }

    return p;
}

LINK build_sum_list(LINK lis1, LINK lis2)
{
    LINK p;

    if((lis1 == NULL) && (lis2 == NULL)) return NULL;

    else if ((lis1 != NULL) && (lis2 == NULL)) {
        p = new_node();
        p->data = lis1->data;
        p->next = build_sum_list(lis1->next,lis2);
        return p;
    }

    else if ((lis1 == NULL) && (lis2 != NULL)) {
        p = new_node();
        p->data = lis2->data;
        p->next = build_sum_list(lis1,lis2->next);
        return p;
    }

    else {
        p = new_node();
        p->data = lis1->data + lis2->data;
        p->next = build_sum_list(lis1->next,lis2->next);
        return p;
    }
}

void print_list(LINK lis)
{
    if(lis == NULL) return;
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next);
    }
}
// Recursively build a filtered linked list including only nodes with value >= x
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list(int *dim);
void print_list(LINK lis);
LINK build_filtered_list(LINK lis, int x);

int main ()
{
    int filter;
    srand(time(NULL));
    int dim = 0;

    LINK head1 = build_list(&dim);

    printf("List:\n");
    print_list(head1);

    printf("Enter filter value: ");
    scanf("%d",&filter);

    LINK fil_lis = build_filtered_list(head1,filter);
    print_list(fil_lis);

    return 0;
}


LINK new_node()
{
    LINK p = malloc(sizeof(*p));

    if(p == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

LINK build_list(int *dim)
{
    LINK p;
    if(*dim == 14) return NULL;
    else {
        p = new_node();
        (*dim)++;

        p->data = rand()%100;
        p->next = build_list(dim);
        return p;
    }
}

void print_list(LINK lis)
{
    if(lis == NULL) {
        printf("NULL\n");
        return; }
    else {
        printf("%d ->\t",lis->data);
        print_list(lis->next);
    }
}

LINK build_filtered_list(LINK lis, int x)
{
    LINK p = NULL;
    if(lis == NULL) return NULL;

    else if(lis->data >= x)
    {
        p = new_node();
        p->data = lis->data;
        p->next = build_filtered_list(lis->next,x);
        return p; }

    else return build_filtered_list(lis->next,x);
}
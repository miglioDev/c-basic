// Recursively build,print and copy a fixed-size (12 node) linked list with random values
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list(int *counter);
LINK print_list(LINK lis);
LINK dup_lis(LINK lis);

int main ()
{
    int c = 0;
    srand(time(NULL));

    LINK head =  build_list(&c);
    print_list(head);

    LINK head_2lis = dup_lis(head);
    printf("\nNew Copied Lis:\n");
    print_list(head_2lis);

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

LINK build_list(int *counter)
{
    LINK p;

    if(*counter >= 12) return NULL;
    else {
        (*counter)++;
        p = new_node();
        p->data = rand()%10;
        p->next = build_list(counter);
        return p;
    }
}

LINK print_list(LINK lis)
{
    if(lis == NULL) return lis;
    else {
        printf("node -> %d\t",lis->data);
        return print_list(lis->next); }
}

LINK dup_lis(LINK lis)
{
    LINK p;
    if(lis == NULL) return NULL;

    else  {
        p = new_node();
        p->data = lis->data;
        p->next = dup_lis(lis->next);
        return p;
    }
}
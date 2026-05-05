#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

LINK build_list(int *dim);

int main ()
{
    int dim = 0;

    LINK head = build_list(&dim);


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

        p->data = rand()%5;
        p->next = build_list(dim);
        return p;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

int main ()
{
    srand(time(NULL));



    return 0;
}

void push_node(LINK *h)
{
    LINK new_node = malloc(sizeof(*new_node)); 

    new_node->data = rand()%10;
    new_node->next = *h;
    *h = new_node;   
}

// op fun with cond

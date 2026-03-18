// Create a minimal singly linked list with one node with dynamic memory 
// assign a value and print it using iteration through nodes
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct linked_list {
    DATA d;
    struct linked_list *next;
};

void printlist(struct linked_list *node);

int main ()
{
    struct linked_list *head = NULL;

    head = (struct linked_list *)malloc(sizeof(struct linked_list));

    head->d = 19;
    head->next = NULL;

    printlist(head);

    return 0;
}

void printlist(struct linked_list *node) {
    while (node != NULL) {
        printf("%d -> ", node->d);
        node = node->next;
    }
}
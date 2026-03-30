// Find the previous node of a given value in a singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

void push_node(node **head);
void print_list(node *head);
LINK find_precedent(LINK p, int x);

int main()
{
    int i = 0,x;
    node *head = NULL;
    srand(time(NULL));

    while(i < 10) {
    push_node(&head);
    i++; }

    print_list(head);

    LINK p = head;
    printf("\nChoose node with value x to find it precedent node value: ");
    scanf("%d",&x);

    LINK result = find_precedent(p,x);
    if(result != NULL) {
        printf("\n\nThe node previus to the node containing %d have value data--> %d",x,result->data); }

    return 0;
}

void push_node(node **head)
{
    node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = rand()%10;

    new_node->next = *head;
    *head = new_node;
}

void print_list(node *head)
{
    node *current = head;

    while(current != NULL) {
        printf("Node data %d -->\t",current->data);
        current = current->next; }
}

LINK find_precedent(LINK p, int x)
{
    int FLAG = 0;;

    if(p == NULL) {
        printf("\nEmpty list!\n");
        return NULL; }

    if(p->data == x) {
        printf("\nIn first node\n");
        return NULL; }

    else {
        while((p->next != NULL) && (!FLAG))
        {
            if(p->next->data == x) {
                FLAG = 1; }
             else 
                p = p->next;
        }
     }

    return p;
}
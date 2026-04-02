// check if a value appears at least twice in a singly linked list;
// practice list, counter and early termination
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct node *LINK;

void append_node(node **head);
void print_list(node *head);
int findnth(LINK p, int x);

int main()
{
    int x,result;
    node *head = NULL;
    srand(time(NULL));

    for(int i = 0; i < 15; i++) 
    {
        append_node(&head);
    }

    print_list(head);

    LINK p = head;
    printf("\nEnter a number to search: ");
    scanf("%d",&x);

    result = findnth(p,x);
    if(result == 0) {
    printf("Not found!\n"); }
        else {
            printf("Found! there are at least two %d in the list",x); }

    return 0;
}

void append_node(node **head)
{
    node *new_node = malloc(sizeof(*new_node));
    if(new_node == NULL) {
        printf("Error: memory fail\n");
        exit(EXIT_FAILURE); }

    new_node->data = rand()%10;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return; }

    node *current = *head;
    while(current->next != NULL) {
         current = current->next;
    }
    current->next = new_node;
} 

void print_list(node *head)
{
    node *current = head;

    while(current != NULL) {
        printf("Node--> %d\t",current->data); 
        current = current->next; }
}

int findnth(LINK p, int x)
{
    node *current = p;
    int counter = 0,flag = 0;

    printf("\n\n== Search ==\n");

    while(current != NULL && !flag) {
        printf("Node--> %d\t counter = %d\n",current->data,counter); 

        if(current->data == x) {
            counter++; }

        if(counter == 2) {
            flag = 1; }

        current = current->next; }

    return flag;
}
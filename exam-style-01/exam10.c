// Exam 10 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

typedef struct {
    char name[DIM];
    int age;
} Element;

typedef struct node {
    Element d;
    struct node *next;
} node;

typedef node *LINK;

LINK create_node(char name[DIM], int age);

int main()
{


    return 0;
}

LINK create_node(char name[DIM], int age)
{
    LINK n = (LINK)malloc(sizeof(node));

    if(n == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(n->d.name,name);
    n->d.age = age; 
    n->next = NULL;

    return n;
}

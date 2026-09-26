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
LINK push_node(LINK head, char name[DIM], int age);

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Error: argument number");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen("r",argv[1]);
    if(fp == NULL) {
        printf("Error: unable to read file");
        exit(EXIT_FAILURE);
    }

    

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

LINK push_node(LINK head, char name[DIM], int age)
{
    LINK n = create_node(name,age);
    if(n == NULL) {
        return n;
    }

    n->next = head;

    return n;
}

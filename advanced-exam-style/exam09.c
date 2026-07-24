// add exam09 text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

typedef struct {
	char name[DIM];
	int age;
} Element;

typedef struct node{
	Element d;
	struct node *next;
} Node;

typedef struct node *LINK;

LINK new_node();
LINK create_listfrom_file(char filename[]);

int main()
{
	LINK head = create_listfrom_file("text.txt");

	return 0;
}

LINK new_node()
{
	LINK n = malloc(sizeof(*n));
	if(n == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return n;
}

LINK create_listfrom_file(char filename[])
{
	LINK p,head,tail;
	char buffer[DIM];
	int x;
	
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("Error on file opening\n");
		exit(EXIT_FAILURE);
	}
	
	head = NULL;
	while(fscanf(fp,"%s19",buffer) == 1)
	{
		p = new_node();
		strcpy(p->d.name,buffer);
		
		fscanf(fp,"%d",&x);
		p->d.age = x;
		p->next = NULL;
		
		if(head == NULL) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}
	}
	fclose(fp);
	
	return head;
}

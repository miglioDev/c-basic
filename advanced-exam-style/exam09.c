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
void print_list(LINK lis);

int main()
{
	int thr;
	
	LINK head = create_listfrom_file("text.txt");
	
	printf("Loaded list:\n");
	print_list(head);
	
	printf("\n\nPick a threshold value: ");
	scanf("%d",&thr);

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

void print_list(LINK lis)
{
	if(lis == NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("---------------\n");
		printf("\nName: %s",lis->d.name);
		printf("\nAge: %d",lis->d.age);
	}
}


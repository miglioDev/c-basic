// Builds a linked list recursively, creates a filtered copy containing only even values,
// then recursively inserts a node with value 0 after each copied even node.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
LINK dup_cond(LINK lis);
void add_node_b_even(LINK lis);

int main()
{
	LINK lis1 = build_list();
	
	printf("Complete list:\n");
	print_list(lis1);
	
	LINK lis_even = dup_cond(lis1);
	add_node_b_even(lis_even);
	print_list(lis_even);
	
	return 0;
}

LINK new_node()
{
	LINK n = malloc(sizeof(*n));
	if(n == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);	
	}
	return n;
}

LINK build_list()
{	
	int x = 0;
	LINK p;
	
	printf("\nEnter new node value: ");
	scanf("%d",&x);
	
	if(x < 0) {
		return NULL;
	} 
	else{		
		p = new_node();
		p->data = x;
		p->next = build_list();
		return p;	
	}
	
	return p;
}

void print_list(LINK lis)
{
	if(lis == NULL) {
		printf("NULL\n");
		return; }
	else {
		printf("%d ->",lis->data);
		print_list(lis->next);
	}
}

LINK dup_cond(LINK lis)
{
	LINK p = NULL;
	
	if(lis == NULL)
		return p;
	if(lis->data%2 == 0) {
		p = new_node();
		p->data = lis->data;
		p->next = dup_cond(lis->next);
		return p;
	}
	else {
		return dup_cond(lis->next);
	}
	return p;
}

void add_node_b_even(LINK lis)
{
	LINK p;
	
	if(lis != NULL) {
		if(lis->data%2 == 0) {
			p = new_node();
			p->data = 0;
			p->next = lis->next;
			lis->next = p;
            add_node_b_even(lis->next->next);
		}
		else 
			add_node_b_even(lis->next);
	}
}

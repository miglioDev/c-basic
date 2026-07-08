// Recursively build two linked lists, create a third list containing the sums of corresponding nodes greater than a threshold,
// and recursively print the resulting list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
LINK r_build_list_sum(LINK l1, LINK l2, int k);

int main ()
{
	int k;
	LINK lis1,lis2,lis3;
	
	printf("\nList 1:\n");
	lis1 = build_list();
	printf("\nList 2:\n");
	lis2 = build_list();
	
	printf("\n\nFull list1:\n");
	print_list(lis1);
	printf("\n\nFull list2:\n");
	print_list(lis2);
	
	printf("\nEnter k: ");
	scanf("%d",&k);
	
	lis3 = r_build_list_sum(lis1,lis2,k);
	printf("\n\n===== LIST 3 =====\n");
	print_list(lis3);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	if(p == NULL) {
		printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

LINK build_list()
{
	int x;
	LINK p;
	
	printf("\nEnter new node value: ");
	scanf("%d",&x);
	
	if(x < 0) 
		return NULL;
	else {
		p = new_node();
		p->d = x;
		p->next = build_list();
		return p;
	}
}

void print_list(LINK lis)
{
	if(lis == NULL) {
		printf("NULL\n");
		return; }
	else {
		printf("%d ->",lis->d);
		print_list(lis->next);
	}
}

LINK r_build_list_sum(LINK l1, LINK l2, int k)
{
	LINK p = NULL;
	int x;
	
	if(l1 == NULL && l2 == NULL) return p;
	
	if(l1 == NULL && l2 != NULL) {
		if(l2->d > k) {
			p = new_node();
			p->d = l2->d;
			p->next = r_build_list_sum(l1, l2->next, k);
			return p;
		}
		else {
			return r_build_list_sum(l1, l2->next, k);
		}
	}
	
	if(l1 != NULL && l2 == NULL) {
		if(l1->d > k) {
			p = new_node();
			p->d = l1->d;
			p->next = r_build_list_sum(l1->next, l2, k);
			return p;
		}
		else {
			return r_build_list_sum(l1->next, l2, k);
		}
	}
	
	x = l1->d + l2->d;
	if(x > k) {
		p = new_node();
		p->d = x;
		p->next = r_build_list_sum(l1->next, l2->next, k);
		return p;
	}
	else {
		return r_build_list_sum(l1->next, l2->next, k);
	}
}

/*
 * Exam 03 — Linked Lists: Search and Deletion Operations
 *
 * Build a linked list of integers by reading the input values from a file,
 * then print the list iteratively.
 *
 * a) Write a recursive function:
 *    void delete_all(LINK *phead, int x);
 *    that removes all occurrences of the value x from the linked list
 *    using a double pointer.
 *
 * b) Write an iterative function:
 *    int nth_occurrence(LINK head, int val, int n);
 *    that returns the position (starting from 0) of the n-th occurrence
 *    of the value val in the linked list, or -1 if it does not exist.
 *    where n = 1 means the first occurrence
 *
 * c) Write a recursive function:
 *    LINK predecessor_rec(LINK head, int val);
 *    that returns a pointer to the predecessor of the first occurrence
 *    of val. If val is the first node or is not present in the list,
 *    the function returns NULL.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK load_list_file(FILE *fp);
void print_list(LINK lis);
void delete_all(LINK *phead, int x);
void delete_value(LINK lis, int x);
int nth_occurrence(LINK lis, int val, int n);
LINK predecessor_rec(LINK lis, int val);

int main()
{
	int x,value,n,pos;
	FILE *fp;
	fp = fopen("text.txt","r");
	if(fp == NULL) {
		printf("Error on file opening\n");
		exit(EXIT_FAILURE);
	}
	LINK head = load_list_file(fp);
	print_list(head);
	
	printf("\nEnter x: ");
	scanf("%d",&x);
	
	delete_all(&head,x);
	print_list(head);
	
	printf("\nEnter value to find nth occurrence: ");
	scanf("%d",&value);
	
	printf("\nEnter n: ");
	scanf("%d",&n);
	
	pos = nth_occurrence(head,value,n);
	if(pos == -1) 
		printf("\nNot found\n");
	else
		printf("\nPosition: %d\n",pos);
	
	printf("\nEnter value to find predecessor node: ");
	scanf("%d",&value);
	LINK pred = predecessor_rec(head,value);
	if(pred == NULL) 
		printf("Prec not found\n");
	else 
		printf("\nPredecessor node: %d\n",pred->d);
	
	fclose(fp);

	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	if(p == NULL) {
		printf("Error: memory allocatio failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

LINK load_list_file(FILE *fp)
{
	int x;
	LINK p,head,tail;
	head = NULL;

	while(fscanf(fp,"%d",&x) == 1) {
		p = new_node();
		p->d = x;
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
	
	return head;
}

void print_list(LINK lis)
{
	while(lis != NULL)
	{
		printf("%d ->",lis->d);
		lis = lis->next;
	}
	printf("NULL\n");
}

void delete_all(LINK *phead, int x)
{
	LINK tmp;
	if(*phead == NULL)
		return;
	
	if((*phead)->d == x) {
		tmp = *phead;
		*phead = (*phead)->next;
		free(tmp);
		delete_all(phead,x);
	}
	else
		delete_value(*phead,x);
}

void delete_value(LINK lis, int x)
{	
	LINK tmp;
	if(lis == NULL) return;
	
	if(lis->next != NULL)
	{
		if(lis->next->d == x)
		{
			tmp = lis->next;
			lis->next = tmp->next;
			free(tmp);
		}
	}
	delete_value(lis->next,x);	
}

int nth_occurrence(LINK lis, int val, int n)
{
	int counter_pos = 0;
	int counter_occ = 0;
	
	while(lis != NULL && counter_occ != n)
	{
		if(lis->d == val) {
			counter_occ++;
		}	
		counter_pos++;
		lis = lis->next;
	}
	
	if(counter_occ != n) return -1;
	else 
		return counter_pos; 
}

LINK predecessor_rec(LINK lis, int val)
{
	if(lis == NULL || lis->next == NULL) return NULL;
	
	if(lis->next->d == val) return lis;
	else 
		return predecessor_rec(lis->next,val);
}

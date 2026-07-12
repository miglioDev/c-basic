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

int main()
{
	FILE *fp;
	fp = fopen("text.txt","r");
	LINK head = load_list_file(fp);
	print_list(head);
	
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

	while(fscanf(fp,"%d",&x) == 1 && fp != NULL) {
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





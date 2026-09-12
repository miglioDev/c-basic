/*
 * Exam 07 — Linked Lists: Recursive Operations and List Copying
 *
 * a) A recursive function:
 *    int counter_val_occ(LINK lis, int val);
 *    that returns the number of occurrences of val in the linked list.
 *    If the value is not present, the function returns 0.
 *
 * b) A recursive function:
 *    LINK dup_if_grt(LINK lis, int thr);
 *    that creates and returns a new linked list containing copies of
 *    all values from the original list that are strictly greater than
 *    the specified threshold, while preserving their relative order.
 *
 * c) An iterative function:
 *    LINK list_from_n_to_m(LINK lis, int n, int m);
 *    that creates and returns a new linked list containing copies of
 *    the nodes from position n to position m (inclusive) of the
 *    original list.
 *
 * d) A recursive function:
 *    void dispose_list(LINK *head);
 *    that properly deallocates all nodes of a linked list.
 *
 * e) A main function that:
 *    - reads a linked list from a text file whose name is provided as
 *      a command-line argument;
 *    - prints the original linked list;
 *    - asks the user for a value and prints its number of occurrences;
 *    - asks for a threshold and prints the filtered linked list
 *      containing only values greater than the threshold;
 *    - asks the user for two positions (n and m), creates a new linked
 *      list containing the corresponding range of nodes, and prints it;
 *    - deallocates all allocated linked lists before terminating.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
void append_node(LINK *lis, int x);
LINK load_list_from_file(char s[]);
void print_list(LINK lis);
int counter_val_occ(LINK lis, int val);
LINK dup_if_grt(LINK lis, int thr);
LINK list_from_n_to_m(LINK lis, int n, int m);
void dispose_list(LINK *head);

int main(int argc, char *argv[])
{
	int occ,val,thr,n,m;
	if(argc != 2) {
		printf("Error file name missing\n");
		exit(EXIT_FAILURE);
	}

	LINK lis1 = load_list_from_file(argv[1]);
	printf("\nList one:\n");
	print_list(lis1);
	
	printf("\nChoose one value: ");
	scanf("%d",&val);
	
	occ = counter_val_occ(lis1,val);
	printf("\nThe value: %d appear %d times",val,occ);
	
	printf("\nChoose threshold: ");
	scanf("%d",&thr);
	LINK lis2 = dup_if_grt(lis1,thr);
	printf("\nList two > than %d:\n",thr);
	print_list(lis2);
	
	printf("\nCopy elements from list 1 choose n and m: ");
	scanf("%d %d",&n,&m);
	LINK lis3 = list_from_n_to_m(lis1, n, m);
	printf("\nList 3 from %d to %d of lis1:\n",n,m);
	print_list(lis3);
	
	dispose_list(&lis1);
	dispose_list(&lis2);
	dispose_list(&lis3);
	
	return 0;
}

LINK new_node()
{
	LINK p = malloc(sizeof(*p));
	if(p == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void append_node(LINK *lis, int x)
{
	LINK p,q;
	p = new_node();
	p->d = x;
	p->next = NULL;
	
	if(*lis == NULL) {
		*lis = p;
		return;
	}
	else {
		q = *lis;
		while(q->next != NULL)
		{
			q = q->next;
		}
	}
	q->next = p;
}

LINK load_list_from_file(char s[])
{	
	FILE *fp = fopen(s,"r");
	if(fp == NULL) {
		printf("Unable to read file\n");
		exit(EXIT_FAILURE);
	}
	
	LINK head = NULL;
	int x;
	
	while(fscanf(fp,"%d",&x) == 1) 
	{
		append_node(&head,x);
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
		printf("%d ->",lis->d);
		print_list(lis->next);
	}
}

int counter_val_occ(LINK lis, int val)
{
	if(lis == NULL) return 0;
	else {
		if(lis->d == val) 
			return 1+counter_val_occ(lis->next,val);
		else 
			return counter_val_occ(lis->next,val);
	}
}

LINK dup_if_grt(LINK lis, int thr)
{
	LINK p;
	
	if(lis == NULL) return NULL;
	else {
		if(lis->d > thr) {
			p = new_node();
			p->d = lis->d;
			p->next = dup_if_grt(lis->next,thr);
			return p;
		}
		else
			return dup_if_grt(lis->next,thr);
	}
}

LINK list_from_n_to_m(LINK lis, int n, int m)
{
	int i = 1;
	LINK head,tail,p;
	head = NULL;
	if(n > m) return head;
	
	while(lis != NULL && i <= m)
	{
		if(i >= n) {
			p = new_node();
			p->d = lis->d;
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
		i++;
		lis = lis->next;
	}
	
	return head;
}

void dispose_list(LINK *head)
{
	LINK tmp;
	if(*head == NULL) return;
	else {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	dispose_list(head);
	}
}




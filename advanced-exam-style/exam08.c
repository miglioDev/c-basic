/*
 * Exam 08 — Linked Lists: Search, Insertion, Splitting, and File Output
 *
 * Build a linked list of positive integers recursively, then implement:
 *
 * a) An iterative function:
 *    LINK find_precd(LINK lis, int x);
 *    that returns a pointer to the node preceding the first occurrence
 *    of x in the linked list. If x is the first element or is not found,
 *    the function returns NULL.
 *
 * b) An iterative function:
 *    void insert_zero_before(LINK *lis, int val);
 *    that inserts a new node containing the value 0 immediately before
 *    the first occurrence of val, using find_precd().
 *
 * c) A recursive function:
 *    void split_list_odd_even(LINK lis, LINK *ehead, LINK etail,
 *                             LINK *ohead, LINK otail);
 *    that splits the original linked list into two newly allocated
 *    linked lists: one containing the even values and one containing
 *    the odd values, while preserving their original order.
 *    The heads and tails of both lists are initialized to NULL by
 *    the main function.
 *
 * d) An iterative function:
 *    void save_on_file(LINK lis, char s[]);
 *    that writes the contents of a linked list to the specified text file.
 *
 * e) A recursive function:
 *    LINK list_sum(LINK l1, LINK l2);
 *    that creates and returns a new linked list whose nodes contain
 *    the sum of the corresponding elements of the even and odd lists.
 *    If one list is longer than the other, the remaining values are
 *    copied unchanged into the resulting list.
 *
 * Main function:
 *    - recursively builds a linked list of positive integers from
 *      user input (input terminates when a negative value is entered);
 *    - prints the original linked list;
 *    - asks the user to choose a value known to be present in the list;
 *    - inserts a node containing 0 before that value;
 *    - splits the updated list into even and odd linked lists;
 *    - prints both the even and odd lists;
 *    - creates the element-wise sum list;
 *    - asks the user for an output file name and saves the resulting
 *      sum list to the specified file.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int d;
	struct node *next;
} node;

typedef struct node *LINK;

LINK new_node();
LINK build_list();
void print_list(LINK lis);
LINK find_precd(LINK lis, int x);
void insert_zero_before(LINK *lis, int val);
void split_list_odd_even(LINK lis, LINK *ehead, LINK etail, LINK *ohead, LINK otail);
LINK list_sum(LINK l1, LINK l2);
void save_on_file(LINK lis, char s[]);

int main ()
{
	int value;
	char filename[20];
	LINK head = build_list();
	
	printf("\nList:\n");
	print_list(head);

	printf("\nChoose one value on the list: ");
	scanf("%d",&value);
	insert_zero_before(&head,value);
	
	printf("\nUpdated List:\n");
	print_list(head);
	
	LINK ohead,otail,ehead,etail;
	ohead = NULL;
	otail = NULL;
	ehead = NULL;
	etail = NULL;
	split_list_odd_even(head,&ehead,etail,&ohead,otail);
	
	printf("\nList of even:\n");
	print_list(ehead);
	
	printf("\nList of odd:\n");
	print_list(ohead);
	
	LINK list_s = list_sum(ehead,ohead);
	
	printf("\nList sum odd and even:\n");
	print_list(list_s);
	
	printf("\nEnter file name: ");
	scanf("%s",filename);
	
	save_on_file(list_s,filename);
	
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
	LINK p = NULL;
	int x;
	
	printf("\nEnter node value: ");
	scanf("%d",&x);
	
	if(x < 0) return NULL;
	else {
		p = new_node();
		p->d = x;
		p->next = build_list();
		return p;
	}
	
	return p;
}

void print_list(LINK lis)
{
	while(lis != NULL)
	{
		printf("%d -> ",lis->d);
		lis = lis->next;
	}	
	
	printf("NULL\n");
}

LINK find_precd(LINK lis, int x)
{
	if(lis == NULL) return NULL;
	if(lis->next != NULL) {
		if(lis->next->d == x) {
			return  lis;
		}
		else 
			return find_precd(lis->next,x);
	}
	else 
		return NULL;
}

void insert_zero_before(LINK *lis, int val)
{
	LINK p;
	
	if((*lis)->d == val) {
		p = new_node();
		p->d = 0;
		p->next = *lis;
		*lis = p;
	}
	else {
		LINK prec = find_precd(*lis,val);
		p = new_node();
		p->d = 0;
		p->next = prec->next;
		prec->next = p;
	}
}

void split_list_odd_even(LINK lis, LINK *ehead, LINK etail, LINK *ohead, LINK otail)
{
	LINK p;
	
	if(lis == NULL) return;
	
	if(lis->d%2 == 0) {
		p = new_node();
		p->d = lis->d;
		p->next = NULL;
		
		if(*ehead == NULL) {
			*ehead = p;
			etail = p;
		}
		else {
			etail->next = p;
			etail = p;
		}
		
		split_list_odd_even(lis->next,ehead,etail,ohead,otail);
	}
	else {
		p = new_node();
		p->d = lis->d;
		p->next = NULL;
		
		if(*ohead == NULL) {
			*ohead = p;
			otail = p;
		}
		else {
			otail->next = p;
			otail = p;
		}
		
		split_list_odd_even(lis->next,ehead,etail,ohead,otail);
	}
}

LINK list_sum(LINK l1, LINK l2)
{
	LINK p = NULL;
	
	if(l1 == NULL && l2 == NULL) return p;
	
	if(l1 == NULL && l2 != NULL) {
		p = new_node();
		p->d = l2->d;
		p->next = list_sum(l1,l2->next);
		return p;
	}

	if(l1 != NULL && l2 == NULL) {
		p = new_node();
		p->d = l1->d;
		p->next = list_sum(l1->next,l2);
		return p;
	}

	else {
		p = new_node();
		p->d = l1->d + l2->d;
		p->next = list_sum(l1->next,l2->next);
		return p;
	}
}

void save_on_file(LINK lis, char s[])
{
	FILE *fp = fopen(s,"w");
	if(fp == NULL) {
		printf("Error unable to create file\n");
		exit(EXIT_FAILURE);
	}

	fprintf(fp,"SUM LIST\n");
	while(lis != NULL)
	{
		fprintf(fp,"%d -> ",lis->d);
		lis = lis->next;
	}
	fprintf(fp,"NULL\n");
	
	fclose(fp);
}

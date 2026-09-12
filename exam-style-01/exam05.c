/*
 * Exam 05 — Linked Lists: Ordered Search and Deletion
 *
 * Build a sorted linked list of integers, then implement:
 *
 * a) A recursive function:
 *    int exist_rec(LINK head, int value);
 *    that returns 1 if value is present in the linked list and 0
 *    otherwise. The search must take advantage of the ascending order
 *    to terminate as soon as possible, without traversing the entire
 *    list unnecessarily.
 *
 * b) An iterative function:
 *    LINK find_prec_and_succ(LINK head, int val, LINK *pred, LINK *succ);
 *    that searches for val in the sorted linked list.
 *    If found, it returns a pointer to the corresponding node and sets
 *    *pred and *succ to its predecessor and successor, respectively
 *    (NULL if either does not exist).
 *    If not found, the function returns NULL and sets *pred and *succ
 *    to the two nodes between which val should be inserted to preserve
 *    the ordering (either pointer may be NULL if the value should be
 *    inserted at the beginning or at the end of the list).
 *
 * c) A recursive function:
 *    LINK del_first_occ(LINK lis, int val);
 *    that removes only the first occurrence of val from the sorted
 *    linked list while preserving the ordering, and returns the new
 *    head of the list. This function is guaranteed to be called only
 *    if val is already present in the list.
 *
 * d) A main function that:
 *    - builds a sorted linked list from user input (terminated by -1,
 *      assuming the values are entered in ascending order);
 *    - reads a value val from the user and uses
 *      find_prec_and_succ() to determine whether it is present;
 *    - if the value is not present, prints the two values between
 *      which it should be inserted;
 *    - removes the first occurrence of val using del_first_occ()
 *      (if present) and prints the updated linked list.
 *
 * Function prototypes:
 *    LINK new_node();
 *    LINK build_list();
 *    void print_list(LINK lis);
 *    int exist_rec(LINK head, int value);
 *    LINK find_prec_and_succ(LINK head, int val, LINK *pred, LINK *succ);
 *    LINK del_first_occ(LINK lis, int val);
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
int exist_rec(LINK head, int value);
LINK find_prec_and_succ(LINK head, int val, LINK *pred, LINK *succ);
LINK del_first_occ(LINK lis, int val);

int main()
{
	int value,pres;
	LINK head = build_list();

	printf("\nList:\n");
	print_list(head);

	printf("Enter value: ");
	scanf("%d",&value);
	
	pres = exist_rec(head,value);
	if(pres)
		printf("%d is on the list\n",value);
	else 
		printf("%d not found\n",value);
		
	LINK target,pred,succ;
	target = find_prec_and_succ(head, value, &pred, &succ);
	if(target != NULL)
		printf("target node: %d\n",target->d);
	else
		printf("Value not found\n");

	if(pred != NULL)
		printf("pred node: %d\n",pred->d);

	if(succ != NULL)
		printf("succ node: %d\n",succ->d);
	
	if(pres) {
		LINK new_head = del_first_occ(head, value);
		printf("\nNew list:\n");
		print_list(new_head);
	}
	else 
		printf("The end\n");

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

LINK build_list()
{
	LINK p = NULL;
	int x;
	
	printf("Enter new node value: ");
	scanf("%d",&x);
	
	if(x < 0) return p;
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
	if(lis == NULL) {
		printf("NULL\n");
		return;
	}
	else {
		printf("%d ->",lis->d);
		print_list(lis->next);
	}
}

int exist_rec(LINK head, int value)
{	
	if(head == NULL) return 0;
	if(head->d == value) return 1;
	if(head->d > value) return 0;
	else 
		return exist_rec(head->next,value);
}

LINK find_prec_and_succ(LINK head, int val, LINK *pred, LINK *succ)
{
	LINK lis,pre;
	
	pre = NULL;
	lis = head;
	
	while(lis != NULL && lis->d < val)
	{
		pre = lis;
		lis = lis->next;
	}
	
	if(lis != NULL && lis->d == val) {
		*pred = pre;
		*succ = lis->next;
		return lis;
	}
	else {
		*pred = pre;
		*succ = lis;
		return NULL;
	}
}

LINK del_first_occ(LINK lis, int val)
{
	LINK tmp;
	
	if(lis == NULL) return lis;
	
	if(lis->d == val) {
		tmp = lis->next;
		free(lis);
		return tmp;
	}	
	lis->next = del_first_occ(lis->next,val);
	return lis;
}















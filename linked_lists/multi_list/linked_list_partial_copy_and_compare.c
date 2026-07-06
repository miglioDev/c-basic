// Copie the nodes between positions n and m whose values are greater than or equal to a threshold k
// into a new linked list, then compare the two lists
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
} node;

typedef struct node *LINK;

void push_node(LINK *lis);
LINK new_node();
void print_list(LINK lis);
LINK copy_from_n_to_m(LINK lis, int n, int m, int k);
int list_cmp(LINK lis1, LINK lis2);

int main()
{
	srand(time(NULL));
	int i,n,m,k,equal;
	LINK lis1 = NULL;

	for(i = 0; i < 15; i++)
	{
		push_node(&lis1);
	}
	print_list(lis1);
	
	printf("Enter n and m (elements of this list will be copied from position n to m)\n");
	scanf(" %d %d",&n,&m);
	printf("Choose k (threshold element)\n");
	scanf("%d",&k);
	
	printf("Lis 2 copied (n to m):\n");
	LINK lis2 = copy_from_n_to_m(lis1,n,m,k);
	print_list(lis2);

	equal = list_cmp(lis1,lis2);
	if(equal) {
		printf("The two list are equal\n"); }
	else {
		printf("The two list are different\n");
	}
	
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

void push_node(LINK *lis)
{
	LINK p = new_node();
	p->data = rand()%10;
	
	p->next = *lis;
	*lis = p;
}

void print_list(LINK lis)
{
	while(lis != NULL)
	{
		printf("%d ->",lis->data);
		lis = lis->next;
	}
	
	printf("NULL\n");
}

LINK copy_from_n_to_m(LINK lis, int n, int m, int k)
{
	int i = 0;
	LINK head,tail,p;
	head = NULL;
	
	while(i < n && lis != NULL)
	{
		lis = lis->next;
		i++;
	}
	
	for(i = n; i < m && lis != NULL; i++)
	{
		if(lis->data > k) {
			p = new_node();
			p->data = lis->data;
			p->next = NULL;
			
			if(head == NULL) {
				head = p;
				tail = p; }
			else {
				tail->next = p;
				tail = p;
			}	
			lis = lis->next;
		}
		else {
			lis = lis->next;
		}
	}
	
	return head;
}

int list_cmp(LINK lis1, LINK lis2)
{
	int flag = 1;
	
	while(lis1 != NULL && lis2 != NULL && flag)
	{
		if(lis1->data != lis2->data) {
		flag = 0;
		}
		else {
		lis1 = lis1->next;
		lis2 = lis2->next;
		}
	}
	
	if(lis1 != NULL || lis2 != NULL) {
	flag = 0;}
	
	if(flag) return 1;
	else 
		return 0;
}

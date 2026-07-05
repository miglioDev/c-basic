// build a linked list, find the node preceding a target value (user input)
// copie all preceding nodes into a second list, then disposes of the original list
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 typedef struct node{
 	int data;
 	struct node *next;
 } node;
 
 typedef struct node *LINK;
 
 LINK new_node();
 void append_node(LINK *head, int x);
 void print_list(LINK lis);
 LINK find_pre(LINK lis, int value, int *pos);
 LINK copy_on_second_list(LINK lis, int pos);
 void dispose_list(LINK *lis);
 
 int main ()
 {
 	srand(time(NULL));
 	int i,x,value,pos;
 	LINK lis1 = NULL;
 	
 	for(i = 0; i < 10; i++)
 	{
 		x = rand()%10;
 		append_node(&lis1,x);
 	}
 	
 	print_list(lis1);
 	
 	printf("Enter value:");
 	scanf("%d",&value);
 	
 	pos = 0;
 	LINK pn = find_pre(lis1,value,&pos);
 	if(pn != NULL) 
 		printf("\nThe value on the precedent node is %d\n",pn->data);
 		
 	if(pos == 0) {
 		printf("Unable to copy\n");
 		return 1; }
 	else {
 		LINK lis2 = copy_on_second_list(lis1,pos);
 		printf("\n\nSecond list:\n");
 		print_list(lis2); }
 		
 	dispose_list(&lis1);
 	
 	return 0;
 }
 
 LINK new_node()
 {
 	LINK p = malloc(sizeof(*p));
 	if(p == NULL) {
 		printf("Error: memory allocation failed\n");
 		exit(EXIT_FAILURE); }
 	return p;	
 }
 
 void append_node(LINK *head, int x)
 {
 	LINK p = new_node();
 	p->data = x;
 	p->next = NULL;
 	
 	if(*head == NULL) {
 		*head = p;
 		return; }
 	else {
 		LINK current = *head;
 		
 		while(current->next != NULL)
 		{
 			current = current->next;
 		}
 		
 		current->next = p;
 	}
 }
 
 void print_list(LINK lis)
 {
 	while(lis != NULL)
 	{
 		printf("%d ->",lis->data);
 		lis = lis->next;
 	}
 	printf("NULL\n\n");
 }
 
 LINK find_pre(LINK lis, int value, int *pos)
 {
 	int flag = 0;
 	
 	if(lis == NULL) {
 		printf("\nEmpty list\n");
 		return NULL; }
 	
 	if(lis->data == value) {
 		printf("\n%d is in the Head of the list\n",value);
 		return NULL; }
 
 	while(lis->next != NULL && !flag) 
 	{
 		(*pos)++;
 		if(lis->next->data == value) 
			flag = 1;
		else
 			lis = lis->next;	
 	}
 	if(flag) return lis;
 	else {
 		printf("\nNot found\n"); 
 		return NULL; }
 }
 
 LINK copy_on_second_list(LINK lis, int pos)
 {
 	int counter = 0;
 	LINK p,head,tail;
 	head = NULL;
 	tail = NULL;
 	
 	while(counter < pos) 
 	{
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
 		counter++;
 	}
 	
 	return head;
 }
 
 void dispose_list(LINK *lis)
 {
 	LINK p;
 	
 	while(*lis != NULL)
 	{
 		p = *lis;
 		*lis = (*lis)->next;
 		free(p); 
 	}
 }

// Implement a static stack using an array with initialization, push, pop, and top operations
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 10
#define EMPTY -1
#define FULL MAXLEN-1

typedef struct STACK{
    DATA s[MAXLEN];
    int top;
} stack;

void clear(stack *stk);
int is_empty(stack *stk);
int is_full(stack *stk);
int push(stack *stk, int i);
int top(stack *stk, DATA *out);
int pop(stack *stk, DATA *out);

int main()
{
    int i,n,ex;
    stack s;
    DATA value; 

    clear(&s);
    printf("How many number will you enter? (n must be < 10):\n\n");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("\nNumber: ");
        scanf("%d",&value);
        push(&s,value);
    }
    
    ex = pop(&s,&value);
    if(!ex) 
    printf("Error: unable to execute pop\n");
        else 
        printf("Pop executed: value = %d\n",value);

    ex = top(&s,&value);
    if(!ex)
    printf("Error: unable to execute top\n");
        else 
        printf("Top executed: value = %d\n",value);

    return 0;
}

void clear(stack *stk)
{
    stk->top = EMPTY;
}

int is_empty(stack *stk)
{
    return(stk->top == EMPTY);   
}

int is_full(stack *stk)
{
    return(stk->top == FULL);
}

int push(stack *stk, int i)
{   
    if(!is_full(stk)) {
        (stk->top)++;
        stk->s[stk->top] = i;
        return 1;
    }
    return 0;
}

int top(stack *stk, DATA *out)
{
    if(!is_empty(stk)) {
        *out = stk->s[stk->top];
        return 1;
    }
    return 0;
}

int pop(stack *stk, DATA *out)
{
    if(!is_empty(stk)) {
        *out = stk->s[stk->top];
        stk->top--;
        return 1;
    }
    return 0;
}

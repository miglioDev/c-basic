// Implement a static stack with push, pop, and top operations using an array-based representation
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 100
#define FULL (MAXLEN-1)
#define EMPTY -1

typedef struct stack{
    DATA s[MAXLEN];
    int top;
} STACK;

void clear(STACK *stk);
int is_empty(STACK *stk);
int is_full(STACK *stk);
int push(DATA i, STACK *stk);
int pop(DATA *out, STACK *stk);
int top(DATA *out, STACK *stk);

int main ()
{
    int t;
    STACK s;
    DATA value;

    clear(&s);
    push(5,&s);
    push(10,&s);
    push(15,&s);

    t = pop(&value,&s);
    if(t)
    printf("Pop executed! value: %d has been removed\n",value);
        else    
        printf("Unable to execute pop\n");

    t = top(&value,&s);
    if(t)
    printf("Top executed: top value is now: %d\n",value);
        else 
        printf("Unable to execute top\n");
}

void clear(STACK *stk) {
    stk->top = EMPTY; }

int is_empty(STACK *stk) {
    return(stk->top == EMPTY);
}

int is_full(STACK *stk) {
    return(stk->top == FULL);
}

int push(DATA i, STACK *stk)
{
    if(!is_full(stk)) {
        (stk->top)++;
        stk->s[stk->top] = i;
        return 1;
    }
    return 0;
}

int pop(DATA *out, STACK *stk)
{
    if(!is_empty(stk)) {
        *out = stk->s[stk->top--];
        return 1;
    }
    return 0;
}

int top(DATA *out, STACK *stk)
{
    if(!is_empty(stk)) {
        *out = stk->s[stk->top];
        return 1; }
    else 
        return 0;
}
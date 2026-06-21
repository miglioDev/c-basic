#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

#define MAXLEN 10
#define EMPTY -1
#define FULL MAXLEN-1

typedef struct STACK{
    DATA s[MAXLEN];
    DATA top;
} stack;

void clear(stack *stk);
int is_empty(stack *stk);
int push(stack *stk, int i);
int top(stack *stk, DATA *out);
int pop(stack *stk, DATA *out);

int main()
{
    stack s;
    DATA value; 

    


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

int push(stack *stk, int i)
{   
    if(!is_empty(stk)) {
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

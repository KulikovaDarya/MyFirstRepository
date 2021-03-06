#include <stdio.h>
#define MAXN 1000
typedef struct stack
{
    int top;
    int data[MAXN];
} stack;
void stack_init(stack * s)
{
    s -> top = -1;
}
void stack_push(stack * s, char n)
{
    s -> data[++s->top] = n;
}
void stack_pop(stack * s)
{
    s -> top--;
}
int stack_top(stack * s)
{
    return s -> data[s->top];
}
int stack_isempty(stack * s)
{
    if (s -> top == -1) return 1;
    else return 0;
}

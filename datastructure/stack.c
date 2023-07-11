#include "stack.h"

struct stack* stack_init()
{
    struct stack* new = malloc(sizeof(struct stack));
    new->top = NULL;
    new->size = 0;
    return new;
}

int stack_empty(struct stack* stack)
{
    if(stack->size == 0)
        return 1;
    
    return 0;
}

int stack_top(struct stack* stack)
{
    if(stack->top == NULL)
        return 0;

    return stack->top->key;
}

int stack_push(struct stack* stack, int value)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = value;
    new->next = stack->top;

    stack->top = new;
    stack->size++;
    return 1;
}
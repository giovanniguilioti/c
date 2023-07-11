#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct node
{
    int key;
    struct node* next;
};

struct stack
{
    int size;
    struct node* top;
};

struct stack* stack_init();

int stack_empty(struct stack*);

int stack_top(struct stack*);

int stack_push(struct stack*, int);

int stack_pop(struct stack*);

#endif
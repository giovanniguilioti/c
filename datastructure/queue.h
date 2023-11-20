#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct node
{
    int key;
    struct node* next;
};

struct queue
{
    struct node* front;
    struct node* rear;
    int size;
};

struct queue* queue_init();

int queue_empty(struct queue*);

int queue_first(struct queue*);

int queue_last(struct queue*);

int queue_enqueue(struct queue*, int);

int queue_dequeue(struct queue*);

#endif
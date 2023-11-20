#include "queue.h"

struct queue* queue_init()
{
    struct queue* new = malloc(sizeof(struct queue));
    new->front = NULL;
    new->rear = NULL;
    new->size = 0;

    return new;
}

int queue_empty(struct queue* queue)
{
    if(queue->size == 0)
        return 1;

    return 0;
}

int queue_first(struct queue* queue)
{
    if(queue->size == 0)
        return 0;
    
    return queue->front->key;
}

int queue_last(struct queue* queue)
{
    if(queue->size == 0)
        return 0;
    
    return queue->rear->key;
}

int queue_enqueue(struct queue* queue, int value)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = value;
    new->next = NULL;

    if(queue->size == 0)
    {
        queue->front = queue->rear = new;
        queue->size++;
        return 1;
    }

    queue->rear->next = new;
    queue->rear = new;
    queue->size++;

    return 1;
}

int queue_dequeue(struct queue* queue)
{
    if(queue->size == 0)
        return 0;

    struct node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;

    if(queue->size == 0)
        queue->rear = queue->front = NULL;

    return 1;
}
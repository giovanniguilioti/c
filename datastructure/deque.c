#include "deque.h"

struct deque* deque_init()
{
    struct deque* deque = malloc(sizeof(struct deque));
    deque->front = deque->back = NULL;

    return deque;
}

int deque_empty(struct deque* deque)
{
    if(deque->front == NULL)
        return 1;
    
    return 0;
}

int deque_size(struct deque* deque)
{
    if(deque->front == NULL)
        return 0;

    struct node* temp = deque->front;

    int i = 1;
    while(temp != NULL)
    {   
        temp = temp->next;
        ++i;
    }

    return i;
}

int deque_front(struct deque* deque)
{
    if(deque->front == NULL)
        return 0;
    
    return deque->front->data;
}

int deque_back(struct deque* deque)
{
    if(deque->back == NULL)
        return 0;
    
    return deque->back->data;
}

int deque_insert_front(struct deque* deque, int value)
{
    struct node* new = malloc(sizeof(struct node));
    if(new == NULL)
        return 0;

    new->data = value;

    if(deque->front == NULL)
    {
        deque->front = new;
        deque->back = deque->front;
        new->next = NULL;
        return 1;
    }

    new->next = deque->front;
    deque->front = new;
    return 1;
}

int deque_insert_back(struct deque* deque, int value)
{

    struct node* new = malloc(sizeof(struct node));
    if(new == NULL)
        return 0;

    new->data = value;
    new->next = NULL;

    if(deque->back == NULL)
    {
        deque->back = new;
        deque->front = deque->back;
        return 1;
    }

    deque->back->next = new;
    deque->back = new;
    return 1;
}

int deque_remove_front(struct deque* deque)
{
    if(deque->front == NULL)
        return 0;

    struct node* temp = deque->front;
    deque->front = deque->front->next;

    free(temp);

    if(deque->front == NULL)
        deque->back = NULL;

    return 1;
}

int deque_remove_back(struct deque* deque)
{
    if(deque->back == NULL)
        return 0;

    if(deque->front == deque->back)
    {
        free(deque->front);
        deque->front = deque->back = NULL;
        return 1;
    }

    struct node* temp = deque->front;

    while(temp->next != deque->back)
        temp = temp->next;

    deque->back = temp;

    free(temp->next);

    deque->back->next = NULL;
    return 1;
}
#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct deque
{
    struct node* front;
    struct node* back;
};

struct deque* deque_init();

int deque_empty(struct deque* deque);

int deque_size(struct deque* deque);

int deque_front(struct deque* deque);

int deque_back(struct deque* deque);

int deque_insert_front(struct deque* deque, int value);

int deque_insert_back(struct deque* deque, int value);

int deque_remove_front(struct deque* deque);

int deque_remove_back(struct deque* deque);

#endif
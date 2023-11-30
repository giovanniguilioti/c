#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

struct node
{
    int key;
    struct node* next;
};

struct list
{
    struct node* head;
    int size;
};

struct list* singly_init();

int singly_empty(struct list*);

int singly_minimum(struct list*);

int singly_maximum(struct list*);

int singly_find(struct list*, int);

int singly_at(struct list*, int);

int singly_push(struct list*, int);

int singly_push_back(struct list*, int);

int singly_insert(struct list*, int, int);

int singly_pop(struct list*);

int singly_pop_back(struct list*);

int singly_remove(struct list*, int);

int singly_delete(struct list*, int);

int singly_clear(struct list*);

#endif
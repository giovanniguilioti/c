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

#endif
#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

int doubly_empty(struct node* head);

int doubly_size(struct node* head);

int doubly_search(struct node* head, int value);

int doubly_element_at(struct node* head, int index);

int doubly_insert_front(struct node** head, int value);

int doubly_insert_at(struct node** head, int index, int value);

int doubly_insert_end(struct node** head, int value);

int doubly_delete_front(struct node** head);

int doubly_delete_at(struct node** head, int index);

int doubly_delete_end(struct node** head);

#endif
#include <stdlib.h>
#include "singly_list.h"

struct list* singly_init()
{
    struct list* new = malloc(sizeof(struct list));
    new->head = NULL;
    new->size = 0;
    return new;
}

int singly_empty(struct list* list)
{
    if(list->size == 0)
        return 1;
    
    return 0;
}

int singly_minimum(struct list* list)
{
    struct node* temp = list->head;
    int min = temp->key;
    while(temp != NULL)
    {
        if(temp->key < min)
            min = temp->key;

        temp = temp->next;
    }
    return min;
}

int singly_maximum(struct list* list)
{
    struct node* temp = list->head;
    int max = temp->key;
    while(temp != NULL)
    {
        if(temp->key > max)
            max = temp->key;

        temp = temp->next;
    }
    return max;
}

int singly_find(struct list* list, int value)
{
    if(singly_empty(list))
        return 0;

    struct node* temp = list->head;
    while(temp != NULL)
    {
        if(temp->key == value)
            return 1;

        temp = temp->next;
    }

    return 0;
}

int singly_at(struct list* list, int idx)
{
    if(idx > (list->size)-1 || idx < 0)
        return -1;

    if(singly_empty(list))
        return -1;

    int i = 0;
    struct node* temp = list->head;
    while(i++ < idx)
        temp = temp->next;

    return temp->key;
}

int singly_push(struct list* list, int key)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = key;
    new->next = list->head;

    list->head = new;
    list->size++;
    return 1;
}

int singly_push_back(struct list* list, int key)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = key;
    new->next = NULL;

    if(singly_empty(list))
    {
        list->head = new;
        list->size++;
        return 1;
    }

    struct node* temp = list->head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    list->size++;
    return 1;
}

int singly_insert(struct list* list, int key, int idx)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = key;
    new->next = NULL;

    if(idx == 0)
    {
        singly_push_front(list, key);
        return 1;
    }
    if(idx == list->size)
    {
        singly_push_back(list, key);
        return 1;
    }

    struct node* temp = list->head;
    int i = 0;
    while(i++ < idx-1)
        temp = temp->next;

    new->next = temp->next;
    temp->next = new;
    list->size++;
    return 1;
}
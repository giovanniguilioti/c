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
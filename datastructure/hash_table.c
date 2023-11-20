#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

struct hash_table* hash_table_init(int size)
{
    struct hash_table* new = malloc(sizeof(struct hash_table));
    new->size = size;
    new->body = malloc(sizeof(struct node*) * size);
    return new;
}

static int hash_table_hash(struct hash_table* hash_table, int value)
{
    return value % hash_table->size;
}

int hash_table_search(struct hash_table* hash_table, int value)
{
    int idx = hash_table_hash(hash_table, value);
    if(hash_table->body[idx] == NULL)
        return 0;
        
    return hash_table->body[idx]->key;
}

int hash_table_insert(struct hash_table* hash_table, int value)
{
    struct node* new = malloc(sizeof(struct node));
    new->key = value;

    if(hash_table->body[hash_table_hash(hash_table, value)] == NULL)
    {
        hash_table->body[hash_table_hash(hash_table, value)] = new;
        new->next = NULL;
        return 1;
    }

    new->next = hash_table->body[hash_table_hash(hash_table, value)]->next;

    hash_table->body[hash_table_hash(hash_table, value)]->next = new;
    return 1;
}


int hash_table_delete(struct hash_table* hash_table, int value)
{
    struct node* temp = hash_table->body[hash_table_hash(hash_table, value)];

    if(temp == NULL)
        return 0;

    if(temp->key == value)
    {
        struct node* rm = temp;
        hash_table->body[hash_table_hash(hash_table, value)]= temp->next;
        free(rm);
        return 1;
    }
    
    while(temp->next != NULL)
    {
        if(temp->next->key == value)
        {
            struct node* rm = temp->next;
            temp->next = rm->next;
            free(rm);
            return 1;
        }

        temp = temp->next;
    }
    
    return 1;
}
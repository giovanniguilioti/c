#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_table.h"

struct hash_table* hash_table_init(int size)
{
    struct hash_table* new = malloc(sizeof(struct hash_table));
    new->size = size;
    new->body = malloc(sizeof(struct node*) * size);
    return new;
}

static unsigned int hash(struct hash_table* hash_table, char* name)
{
    int length = strlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; ++i)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i] % hash_table->size);
    }
    
    return hash_value;
}

int hash_table_search(struct hash_table* hash_table, char* name)
{
    int idx = hash(hash_table, name);
    if(hash_table->body[idx] == NULL)
        return 0;
        
    return 1;
}

int hash_table_insert(struct hash_table* hash_table, char* name)
{
    struct node* new = malloc(sizeof(struct node));
    new->name = name;

    if(hash_table->body[hash(hash_table, name)] == NULL)
    {
        hash_table->body[hash(hash_table, name)] = new;
        new->next = NULL;
        return 1;
    }

    new->next = hash_table->body[hash(hash_table, name)]->next;

    hash_table->body[hash(hash_table, name)]->next = new;
    return 1;
}


int hash_table_delete(struct hash_table* hash_table, char* name)
{
    struct node* temp = hash_table->body[hash(hash_table, name)];

    if(temp == NULL)
        return 0;

    if(strcmp(temp->name, name) == 0)
    {
        struct node* rm = temp;
        hash_table->body[hash(hash_table, name)]= temp->next;
        free(rm);
        return 1;
    }
    
    while(temp->next != NULL)
    {
        if(strcmp(temp->next->key, name) == 0)
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
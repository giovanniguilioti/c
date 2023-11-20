#ifndef HASH_TABLE_H
#define HASH_TABLE_H

struct node
{
    int key;
    struct node* next;
};

struct hash_table
{
    int size;
    struct node** body;
};

struct hash_table* hash_table_init();

int hash_table_search(struct hash_table*, int);

int hash_table_insert(struct hash_table*, int);

int hash_table_delete(struct hash_table*, int);

#endif
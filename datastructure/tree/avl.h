#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node* left;
    struct node* right;
};

int avl_empty(struct node* root);

int avl_nodes(struct node* node);

int avl_height(struct node* node);

struct node* avl_min_value(struct node* node);

struct node* avl_max_value(struct node* node);

int avl_search(struct node* node, int key);

struct node* avl_insert(struct node* root, int key);

struct node* avl_remove(struct node* node, int key);

#endif
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>

struct node
{
    int data;
    enum {BLACK, RED} color;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct rbtree
{
    struct node* root;
    struct node* nil;
};

int rbt_init(struct rbtree* tree);

int rbt_empty(struct node* root);

int rbt_nodes(struct node* node);

int rbt_search(struct node* node, int key);

int rbt_insert(struct rbtree* tree, struct node* key);

int rbt_delete(struct rbtree* tree, struct node* node);

#endif
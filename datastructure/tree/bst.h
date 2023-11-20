#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct bst_node
{
    int key;
    struct bst_node* left;
    struct bst_node* right;
};

struct bst_node* bst_new_node();

struct bst_node* bst_inorder(struct bst_node* node);

struct bst_node* bst_preorder(struct bst_node* node);

struct bst_node* bst_postorder(struct bst_node* node);

struct bst_node* bst_search(struct bst_node* node, int key);

struct bst_node* bst_search_iterative(struct bst_node* node, int key);

struct bst_node* bst_minimum(struct bst_node* node);

struct bst_node* bst_maximum(struct bst_node* node);

struct bst_node* bst_successor(struct bst_node* node);

struct bst_node* bst_predecessor(struct bst_node* node);

#endif
#include <stdlib.h>
#include "bst.h"

struct bst_node* bst_new_node(int key)
{
    struct bst_node* node = malloc(sizeof(struct bst_node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct bst_node* bst_inorder(struct bst_node* node)
{
    if(node == NULL)
        return;

    bst_inorder(node->left);
    // process
    bst_inorder(node->right);
}

struct bst_node* bst_preorder(struct bst_node* node)
{
    if(node == NULL)
        return;

    // process
    bst_inorder(node->left);
    bst_inorder(node->right);
}

struct bst_node* bst_postorder(struct bst_node* node)
{
    if(node == NULL)
        return;

    bst_inorder(node->left);
    bst_inorder(node->right);
    // process
}

struct bst_node* bst_search(struct bst_node* node, int key)
{
    if(node == NULL || node->key == key)
        return node;

    if(key < node->key)
        return bst_search(node->left, key);
    else
        return bst_search(node->right, key);
}

struct bst_node* bst_search_iterative(struct bst_node* node, int key)
{
    while(node != NULL && node->key != key)
    {
        if(key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

struct bst_node* bst_minimum(struct bst_node* node)
{
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct bst_node* bst_maximum(struct bst_node* node)
{
    while(node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

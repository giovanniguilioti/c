#include <stdlib.h>
#include "bst.h"

struct bst_node* bst_new_node(int key)
{
    struct bst_node* node = malloc(sizeof(struct bst_node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

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

struct bst_node* bst_successor(struct bst_node* node)
{
    if(node->right != NULL)
        return bst_minimum(node->right);

    struct bst_node* aux = node->parent;
    while(aux != NULL && node == aux->right)
    {
        node = aux;
        aux = aux->parent;
    }
    return aux;
}

struct bst_node* bst_predecessor(struct bst_node* node)
{
    if(node->left != NULL)
        return bst_maximum(node->left);

    struct bst_node* aux = node->parent;
    while(aux != NULL && node == aux->left)
    {
        node = aux;
        aux = aux->parent;
    }
    return aux;
}

int bst_insert(struct bst_node* tree, int key)
{
    struct bst_node* aux = tree;
    struct bst_node* parent = tree;
    while(aux != NULL)
    {
        parent = aux;
        if(key < aux->key)
            aux = aux->left;
        else
            aux = aux->right;
    }

    struct bst_node* new = bst_new_node(key);
    new->parent = parent;

    if(parent == NULL)
        tree = new;
    else if(key < parent->key)
        parent->left = new;
    else
        parent->right = new;

    return 1;
}

static void bst_transplant(struct bst_node* tree, struct bst_node* u, struct bst_node* v)
{
    if(u->parent == NULL)
        tree = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if(v != NULL)
        v->parent = u->parent;
}

int bst_delete(struct bst_node* tree, int key)
{
    struct bst_node* node = bst_search(tree, key);

    if(node->left == NULL)
        bst_transplant(tree, node, node->right);
    else if(node->right == NULL)
        bst_transplant(tree, node, node->left);
    else
    {
        struct bst_node* aux = bst_minimum(node->right);
        if(aux != node->right)
        {
            bst_transplant(tree, aux, aux->right);
            aux->right = node->right;
            aux->right->parent = aux;
        }
        bst_transplant(tree, node, aux);
        aux->left = node->left;
        aux->left->parent = aux;
    }

    return 1;
}

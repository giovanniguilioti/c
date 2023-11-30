#include "rbt.h"

struct node* rbt_new_node(int data)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    return new;
}

int rbt_init(struct rbtree* tree)
{
    struct node *nil = malloc(sizeof(struct node));
    if(nil == NULL)
        return 0;
    
    nil->color = BLACK;
    nil->left = nil->right = nil->parent = NULL;

    tree->root = nil;
    tree->nil = nil;

    return 1;
}

int rbt_empty(struct node* root)
{
    if(root == NULL)
        return 1;
    
    return 0;
}

int rbt_nodes(struct node* node)
{
    if(node == NULL)
        return 0;
    
    return 1 + rbt_nodes(node->left) + rbt_nodes(node->right);
}

void rbt_left_rotate(struct rbtree* tree, struct node* node)
{
    struct node* aux = node->right;
    node->right = aux->left;

    if(aux->left != NULL)
        aux->left->parent = node;

    aux->parent = node->parent;

    if(node->parent == NULL)
        tree->root = aux;
    else if(node == node->parent->left)
        node->parent->left = aux;
    else
        node->parent->right = aux;

    aux->left = node;
    node->parent = aux;
}

void rbt_right_rotate(struct rbtree* tree, struct node* node)
{
    struct node* aux = node->left;
    node->left = aux->right;

    if (aux->right != NULL)
        aux->right->parent = node;

    aux->parent = node->parent;

    if (node->parent == NULL)
        tree->root = aux;
    else if (node == node->parent->right)
        node->parent->right = aux;
    else
        node->parent->left = aux;

    aux->right = node;
    node->parent = aux;
}

void rbt_insert_fixup(struct rbtree* tree, struct node* key)
{
    while(key->parent->color == RED)
    {
        if(key->parent == key->parent->parent->left)
        {
            struct node* aux = key->parent->parent->right;

            if(aux->color == RED)
            {
                key->parent->color = BLACK;
                aux->color = BLACK;
                key->parent->parent->color = RED;
                key = key->parent->parent;
            }
            else
            {
                if(key == key->parent->right)
                {
                    key = key->parent;
                    rbt_left_rotate(tree, key);
                }

                key->parent->color = BLACK;
                key->parent->parent->color = RED;
                rbt_right_rotate(tree, key->parent->parent);
            }
        }
        else
        {
            struct node* aux = key->parent->parent->left;

            if(aux->color == RED)
            {
                key->parent->color = BLACK;
                aux->color = BLACK;
                key->parent->parent->color = RED;
                key = key->parent->parent;
            }
            else
            {
                if(key == key->parent->left)
                {
                    key = key->parent;
                    rbt_right_rotate(tree, key);
                }

                key->parent->color = BLACK;
                key->parent->parent->color = RED;
                rbt_left_rotate(tree, key->parent->parent);
            }
        }
        
        tree->root->color = BLACK;
    }
}

int rbt_search(struct node* node, int key)
{
    if(node == NULL)
        return 0;
    if(key == node->data)
        return 1;
    if(key < node->data)
        return rbt_search(node->left, key);
    if(key > node->data)
        return rbt_search(node->right, key);
}

int rbt_insert(struct rbtree* tree, struct node* key)
{
    struct node* aux = NULL;
    struct node* node = tree->root;

    while(node != NULL)
    {
        aux = node;

        if(key->data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    key->parent = aux;

    if(aux == NULL)
        tree->root = key;
    else if(key->data < aux->data)
        aux->left = key;
    else
        aux->right = key;

    key->left = NULL;
    key->right = NULL;
    key->color = RED;

    rbt_insert_fixup(tree, key);
}

void rbt_transplant(struct rbtree* tree, struct node* aux1, struct node* aux2)
{
    if (aux1->parent == NULL)
        tree->root = aux2;
    else if(aux1 == aux1->parent->left)
        aux1->parent->left = aux2;
    else
        aux1->parent->right = aux2;

    aux2->parent = aux1->parent;
}

struct node* rbt_minimum(struct node* node)
{
    while(node->left != NULL)
        node = node->left;

    return node;
}

void rbt_delete_fixup(struct rbtree* tree, struct node* node)
{
    struct node* aux = NULL;

    while(node != tree->root && node->color == BLACK)
    {
        if(node == node->parent->left)
        {
            aux = node->parent->right;
            if (aux->color == RED)
            {
                aux->color = BLACK;
                node->parent->color = RED;
                rbt_left_rotate(tree, node->parent);
                aux = node->parent->right;
            }
            if(aux->left->color == BLACK && aux->right->color == BLACK)
            {
                aux->color = RED;
                node = node->parent;
            }
            else
            {
                if(aux->right->color == BLACK)
                {
                    aux->left->color = BLACK;
                    aux->color = RED;
                    rbt_right_rotate(tree, aux);
                    aux = node->parent->right;
                }

                aux->color = node->parent->color;
                node->parent->color = BLACK;
                aux->right->color = BLACK;
                rbt_left_rotate(tree, node->parent);
                node = tree->root;
            }
            
        }
        else
        {
            aux = node->parent->left;
            if (aux->color == RED)
            {
                aux->color = BLACK;
                node->parent->color = RED;
                rbt_right_rotate(tree, node->parent);
                aux = node->parent->left;
            }
            if(aux->right->color == BLACK && aux->left->color == BLACK)
            {
                aux->color = RED;
                node = node->parent;
            }
            else
            {
                if(aux->left->color == BLACK)
                {
                    aux->right->color = BLACK;
                    aux->color = RED;
                    rbt_left_rotate(tree, aux);
                    aux = node->parent->left;
                }

                aux->color = node->parent->color;
                node->parent->color = BLACK;
                aux->left->color = BLACK;
                rbt_right_rotate(tree, node->parent);
                node = tree->root;
            }
        }
    }

    node->color = BLACK;
}

int rbt_delete(struct rbtree* tree, struct node* node)
{
    struct node* aux = node;
    struct node* temp = NULL;
    int original_color = aux->color;

    if(node->left == NULL)
    {
        temp = node->right;
        rbt_transplant(tree, node, node->right);
    }
    else if(node->right == NULL)
    {
        temp = node->left;
        rbt_transplant(tree, node, node->left);
    }
    else
    {
        aux = rbt_minimum(node->right);
        original_color = aux->color;
        temp = aux->left;

        if(aux->parent == node)
            temp->parent = aux;
        else
        {
            rbt_transplant(tree, aux, aux->right);
            aux->right = node->right;
            aux->right->parent = aux;
        }

        rbt_transplant(tree, node, aux);
        aux->left = node->left;
        aux->left->parent = aux;
        aux->color = node->color;        
    }

    if(original_color == BLACK)
        rbt_delete_fixup(tree, temp);
}
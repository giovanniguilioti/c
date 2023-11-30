#include "avl.h"

static int get_max(int a, int b)
{
    return (a > b)? a : b;
}

struct node* new_node(int data)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = data;
    new->height = 1;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int avl_empty(struct node* root)
{
    if(root == NULL)
        return 1;
    
    return 0;
}

int avl_nodes(struct node* node)
{
    if(node == NULL)
        return 0;
    
    return 1 + avl_nodes(node->left) + avl_nodes(node->right);
}

int avl_height(struct node* node)
{
    if(node == NULL)
        return -1;

    return node->height;
}

int avl_rebalance(struct node* node)
{
    if(node == NULL)
        return 0;

    return avl_height(node->left) - avl_height(node->right);
}

static struct node* avl_right_rotate(struct node* node)
{
    struct node* aux1 = node->left;
    struct node* aux2 = aux1->right;

    aux1->right = node;
    node->left = aux2;

    node->height = get_max(avl_height(node->left), avl_height(node->right)) + 1;
    aux1->height = get_max(avl_height(aux1->left), avl_height(aux2->right)) + 1;

    return aux1;
}

static struct node* avl_left_rotate(struct node* node)
{
    struct node* aux1 = node->right;
    struct node* aux2 = aux1->left;

    aux1->left = node;
    node->right = aux2;

    node->height = get_max(avl_height(node->left), avl_height(node->right)) + 1;
    aux1->height = get_max(avl_height(aux1->left), avl_height(aux2->right)) + 1;

    return aux1;
}

struct node* avl_min_value(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* avl_max_value(struct node* node)
{
    struct node* current = node;
 
    while (current && current->right != NULL)
        current = current->right;
 
    return current;
}


int avl_search(struct node* node, int key)
{
    if(node == NULL)
        return 0;
    if(key == node->data)
        return 1;
    if(key < node->data)
        return avl_search(node->left, key);
    if(key > node->data)
        return avl_search(node->right, key);
}

struct node* avl_insert(struct node* node, int key)
{
    if(node == NULL)
        node = new_node(key);

    if (key < node->data)
        node->left = avl_insertt(node->left, key);
    else if (key > node->data)
        node->right = avl_insertt(node->right, key);
    else
        return node;

    node->height = 1 + get_max(avl_height(node->left), avl_height(node->right));

    int balance = avl_rebalance(node);

    if(balance > 1 && key < node->left->data)
        return avl_right_rotateate(node);
    
    if(balance < -1 && key > node->right->data)
        return avl_left_rotateate(node);

    if(balance > 1 && key > node->left->data)
    {
        node->left = avl_left_rotateate(node->left);
        return avl_right_rotateate(node);
    }

    if(balance < -1 && key < node->right->data)
    {
        node->right = avl_right_rotateate(node->right);
        return avl_left_rotateate(node);
    }

    return node;
}

struct node* avl_remove(struct node* node, int key)
{
    if(node == NULL)
        return node;

    if(key < node->data)
        node->left = avl_remove(node->left, key);
    else if(key > node->data)
        node->right = avl_remove(node->right, key);
    else
    {
        if( (node->left == NULL) || (node->right == NULL))
        {
            struct node* temp = node->left ? node->left : node->right;

            if(temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;

            free(temp);
        }
        else
        {
            struct node* temp = avl_min_valueueNode(node->right);

            node->data = temp->data;

            node->right = avl_remove(node->right, temp->data);
        }
    }

    if (node == NULL)
      return node;

    node->height = 1 + get_max(avl_height(node->left), avl_height(node->right));

    int balance = avl_rebalance(node);

    if(balance > 1 && avl_rebalance(node->left) >= 0)
        return avl_right_rotateate(node);
    
    if(balance < -1 && avl_rebalance(node->right) <= 0)
        return avl_left_rotateate(node);

    if(balance > 1 && key > avl_rebalance(node->left) < 0)
    {
        node->left = avl_left_rotateate(node->left);
        return avl_right_rotateate(node);
    }

    if(balance < -1 && key < avl_rebalance(node->right) > 0)
    {
        node->right = avl_right_rotateate(node->right);
        return avl_left_rotateate(node);
    }

    return node;
}
#include "doubly_list.h"

int doubly_empty(struct node* head)
{
    if(head == NULL)
        return 1;

    return 0;
}

int doubly_size(struct node* head)
{
    if(head == NULL)
        return 0;

    struct node* temp = head->next;

    int i = 1;
    while(temp != NULL)
    {   
        temp = temp->next;
        ++i;
    }

    return i;
}

int doubly_search(struct node* head, int value)
{
    if(doubly_empty(head))
        return -1;

    struct node* temp = head;
    int i = 0;
    while(temp != NULL)
    {
        if(temp->data == value)
            return i;
        
        temp = temp->next;
        ++i;
    }

    return -1;
}

int doubly_element_at(struct node* head, int index)
{
    if(doubly_empty(head))
        return 0;

    if(index < 0)
        return 0;

    if(index >= doubly_size(head))
        return 0;

    struct node* temp = head;
    int i = 0;
    while(i < index)
    {
        temp = temp->next;
        ++i;
    }
    
    return temp->data;
}

int doubly_insert_front(struct node** head, int value)
{
    struct node* new = malloc(sizeof(struct node));
    if(new == NULL)
        return 0;

    new->data = value;
    new->next = *head;
    new->prev = NULL;

    if(doubly_empty(*head))
    {
        *head = new;
        return 1;
    }

    (*head)->prev = new;
    *head = new;

    return 1;
}

int doubly_insert_at(struct node** head, int index, int value)
{
    if(index < 0 || index > doubly_size(*head))
        return 0;

    struct node* new = malloc(sizeof(struct node));
    if(new == NULL)
        return 0;

    new->data = value;
    new->next = NULL;

    if(index == 0)
    {
        new->next = *head;
        new->prev = NULL;
        *head = new;
        return 1;
    }

    struct node* temp = *head;
    int i = 1;
    while(i < index)
    {
        temp = temp->next;
        ++i;
    }

    new->prev = temp;
    new->next = temp->next;
    if(new->next != NULL)
        new->next->prev = new;

    temp->next = new;
    return 1;
}

int doubly_insert_end(struct node** head, int value)
{
    struct node* new = malloc(sizeof(struct node));
    if(new == NULL)
        return 0;
    
    new->data = value;
    new->next = NULL;

    if(doubly_empty(*head))
    {
        new->prev = NULL;
        *head = new;
        return 1;
    }

    struct node* temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;
    return 1;
}

int doubly_delete_front(struct node** head)
{
    if(doubly_empty(*head))
        return 0;

    struct node* temp = *head;
    *head = (*head)->next;

    if(*head != NULL)
        (*head)->prev = NULL;

    free(temp);
    return 1;
}

int doubly_delete_at(struct node** head, int index)
{
    if(doubly_empty(*head))
        return 0;

    if(index < 0 || index >= doubly_size(*head))
        return 0;

    struct node* temp = *head;

    if(index == 0)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        
        free(temp);
        return 1;
    }

    int i = 0;
    while(i < index)
    {
        temp = temp->next;
        ++i;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return 1;
}

int doubly_delete_end(struct node** head)
{
    if(doubly_empty(*head))
        return 0;

    struct node* temp = *head;

    if(doubly_size(*head) == 1)
    {
        free(temp);
        *head = NULL;
        return 1;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    return 1;
}
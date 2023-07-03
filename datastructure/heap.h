#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>

struct heap
{
    int* arr;
    int* size;
};

struct heap* heap_init(int n);

int heap_parent(int i);

int heap_left(int i);

int heap_right(int i);

//max
int max_heapify(struct heap*, int i);

int build_max_heap(struct heap* heap, int size);

//min
int min_heapify(struct heap*, int i);

int build_min_heap(struct heap* heap, int size);

#endif
#include "datastructure/heap.h"

int heap_sort(struct heap* heap, int size)
{
    for(int i = size; i > 1; --i)
    {
        heap->arr[1] ^= heap->arr[i] ^= heap->arr[1] ^= heap->arr[i];
        --(heap->size);
        max_heapify(heap, 1);
    }
}
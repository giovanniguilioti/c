#include "heap.h"
#include "math.h"

struct heap* heap_init(int n)
{
    struct heap* heap = (struct heap*)malloc(sizeof(struct heap));
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int) * n);

    return heap;
}

int heap_parent(int i)
{
    return floor(i/2);
}

int heap_left(int i)
{
    return 2*i;
}

int heap_right(int i)
{
    return 2*i + 1;
}

int max_heapify(struct heap* heap, int i)
{
    int l = heap_left(i);
    int r = heap_right(i);
    int largest;

    if(l <= heap->size && heap->arr[l] > heap->arr[i])
        largest = l;
    else
        largest = i;

    if(r <= heap->size && heap->arr[r] > heap->arr[largest])
        largest = r;

    if(largest != i)
    {
        heap->arr[i] ^= heap->arr[largest] ^= heap->arr[i] ^= heap->arr[largest];
        max_heapify(heap, largest);
    }
}

int build_max_heap(struct heap* heap, int size)
{
    heap->size = size;
    
    for(int i = floor(size/2); i > 0; --i)
        max_heapify(heap, i);
}

int min_heapify(struct heap* heap, int i)
{
    int l = heap_left(i);
    int r = heap_right(i);
    int smallest;

    if(l <= heap->size && heap->arr[l] < heap->arr[i])
        smallest = l;
    else
        smallest = i;

    if(r <= heap->size && heap->arr[r] < heap->arr[smallest])
        smallest = r;

    if(smallest != i)
    {
        heap->arr[i] ^= heap->arr[smallest] ^= heap->arr[i] ^= heap->arr[smallest];
        min_heapify(heap, smallest);
    }
}

int build_min_heap(struct heap* heap, int size)
{
    heap->size = size;
    
    for(int i = floor(size/2); i > 0; --i)
        min_heapify(heap, i);
}
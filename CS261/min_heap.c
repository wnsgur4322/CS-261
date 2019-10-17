#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"
#include <stdio.h>

struct minHeap
{
    struct dynarray *data;
    int size;
};

void initHeap(struct minHeap *heap)
{
    assert(heap);
    heap->data = dynarray_create();
    heap->size = 0;
}

TYPE getMin(struct minHeap *heap)
{
    assert(heap);
    assert(heap->data);
    return dynarray_get(heap->data, 0);
}

void insertHeap(struct minHeap *heap, TYPE value)
{
    assert(heap);
    assert(heap->data);
    /* Insert at the end of array (heap) */
    dynarray_push(heap->data, value);
    heap->size++;
    /* Percolating up */
    int childIdx = heap->size - 1;
    int parentIdx = (heap->size - 2) / 2;
    /* this is the value at Parent */
    TYPE parentValue = dynarray_get(heap->data, parentIdx);
    /* Percolate up when parent value is larger than child */
    while(parentValue > value)
    {
        /* Set child node to parent value */
        dynarray_set(heap->data, childIdx, parentValue);
        /* End condition: put new value at root */
        if (parentIdx == 0)
        {
            childIdx = 0;
            break;
        }
        /* Go up, old parent becomes new child, then get new child's parent */
        childIdx = parentIdx;
        parentIdx = (childIdx - 1)/2;
        parentValue = dynarray_get(heap->data, parentIdx);
    }
    /* need to set the value */
    /* value should go to childIdx */
    /* when at root and loop breaks, childIdx == 0, parentIdx == 0 */
    dynarray_set(heap->data, childIdx, value);
}
/* Unit testing, should disable if used in other programs */
void main()
{
    struct minHeap heap;
    int i;
    initHeap(&heap);
    insertHeap(&heap, 2.1);
    printf("%.4lf\n", getMin(&heap));
    insertHeap(&heap, 2.0);
    printf("%.4lf\n", getMin(&heap));
    insertHeap(&heap, 3.5);
    printf("%.4lf\n", getMin(&heap));
    insertHeap(&heap, 1.1);
    printf("%.4lf\n", getMin(&heap));
    insertHeap(&heap, 1.2);
    printf("%.4lf\n", getMin(&heap));
    insertHeap(&heap, 5.7);
    insertHeap(&heap, 0.5);
    insertHeap(&heap, 2.2);
    insertHeap(&heap, 3.3);
    for (i = 0;i < 8;i++)
        printf("%.4lf\n", dynarray_get(heap.data, i));
}

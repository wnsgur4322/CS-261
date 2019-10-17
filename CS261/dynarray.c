#include "dynarray.h"
#include <stdlib.h>
#include <assert.h>

#define INITIAL_ARRAY_SIZE 4

struct dynarray{
   TYPE *data;
   int size;
   int capacity;
};

struct dynarray *dynarray_create()
{
/* Option 1: Correct */
    struct dynarray *arr;
    arr = (struct dynarray *) malloc(sizeof(struct dynarray));
    assert(arr!=0);

/*
Option 2: Wrong
    struct dynarray arr0;
    struct dynarray *arr = &arr0;  /* Wrong: on the call stack 
*/
/* 
Option 3: Also OK */
/*
    struct dynarray arr0;
    struct dynarray *arr = &arr0;
*/

    arr->data = (TYPE *)malloc(sizeof(TYPE) * INITIAL_ARRAY_SIZE);
    assert(arr->data != 0);
    arr->size = 0;
    arr->capacity = INITIAL_ARRAY_SIZE;
    return arr; /* Option 1/2: return pointer */

/*    return arr0; /* Option 3: going to be copied after returned */
}

void dynarray_insert(struct dynarray *arr, int idx, TYPE val)
{
    TYPE temp;
    int i;
    assert(arr!=0 && arr->data !=0);
    if (arr->size == arr->capacity)
        _dynarray_doublesize(arr);
    for (i=arr->size-1;i>=idx;i--)
       arr->data[i+1] = arr->data[i];
    arr->data[idx] = val;
}

void dynarray_push(struct dynarray *arr, TYPE val)
{
   TYPE *ptr;
   int i;
   assert(arr!=0 && arr->data!=0);
   if (arr->size == arr->capacity)
       _dynarray_doublesize(arr);
   arr->data[arr->size] = val; 
   arr->size++;
}

void _dynarray_doublesize(struct dynarray *arr)
{
    TYPE *ptr;
    int i;
    assert(arr!=0);
    ptr = arr->data;
    arr->data = (TYPE *) malloc(sizeof(TYPE) * arr->capacity * 2);
    assert(arr->data !=0);
    arr->capacity = arr->capacity * 2;
    for (i=0;i<arr->size;i++)
       arr->data[i] = ptr[i];
    free(ptr);
    ptr = NULL;
}

void dynarray_free(struct dynarray* da)
{
    if (da != 0)
    {
        if (da->data != 0)
        {
            free(da->data);
            da->data = NULL;
        }
        free(da);
        da = NULL;
    }
}

void dynarray_set(struct dynarray *arr, int idx, TYPE value)
{
    assert(arr);
    assert(arr->data);
    arr->data[idx] = value;
}

TYPE dynarray_get(struct dynarray *arr, int idx)
{
    assert(arr);
    assert(arr->data);
    return arr->data[idx];
}
/*
void main()
{

   struct dynarray *arr;
   int i;
   arr = dynarray_create();
   for (i=0;i<1000000;i++)
       dynarray_push(arr, (double)i);
   dynarray_free(arr);
}
*/

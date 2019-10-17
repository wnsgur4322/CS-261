/*	dynArr.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamicArrayDeque.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
	int beg;        /* Beginning of the 'floating' array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
	v->beg = 0;

}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.
*/
DynArr* createDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
	v->beg = 0;
}

/* Deallocate data array and the dynamic array ure.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying deque to be the size cap

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
	
	Note: this set capacity should be of a deque one, hence it should be 
	a bit different from a normal _dynArrSetCapacity (the array elements
	start from beg)
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
	/* FIXME: Please implement this function */
}

/* ************************************************************************
 Deque Interface Functions
 *************************************************************************/
/* Add a new value at the front of the deque */
void addFrontDynArr(DynArr *v, TYPE val){
	/* FIXME: Please implement this function */

}

/* Remove a value from the front of the deque */
void removeFrontDynArr(DynArr *v){
	/* FIXME: Please implement this function */
}

/* Add a new value at the back of the deque */
void addBackDynArr(DynArr *v, TYPE val)
{
	/* FIXME: Please implement this function */
}

/* Remove the value at the back of the deque */
void removeBackDynArr(DynArr *v){
	/* FIXME: Please implement this function */
}

/* Return the value at the front of the deque */
TYPE frontDynArr(DynArr *v){
	/* FIXME: Please implement this function */
}

/* Return the value at the back of the deque */
TYPE backDynArr(DynArr *v){
	/* FIXME: Please implement this function */
}

void printDynArr(DynArr *v)
{
	int i = 0;
	printf("==================\n");
	for (i = 0; i < v->capacity; i++)  /*RAM: Made this capacity so you can see the full array! */
          {
            printf("Item %d in the Deque == %d\n", i, v->data[(v->beg+i)%v->capacity]);
          }
	printf("==================\n");


}
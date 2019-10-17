/*
 * This file contains the implementation of a priority queue.
 *
 * You must complete the implementations of these functions:
 *   pq_insert()
 *   pq_first()
 *   pq_remove_first()
 */

#include <stdlib.h>
#include <assert.h>

#include "dynarray.h"
#include "pq.h"

// This is the initial capacity that will be allocated for the heap.
#define INITIAL_HEAP_CAPACITY 16

/*
 * This is the definition of the structure we will use to represent the
 * priority queue.  It contains only a dynamic array, which will be used to
 * store the heap underlying the priority queue.
 */
struct pq {
  struct dynarray* heap;
};


/*
 * This is an auxiliary structure that we'll use to represent a single element
 * in the priority queue.  It contains two fields:
 *
 *   priority - the priority value assigned to the item
 *   item - the pointer to the data item represented by this element
 *
 * Both of these will come directly from the corresponding values passed to
 * pq_insert().
 */
struct pq_elem {
  int priority;
  void* item;
};


/*
 * This function allocates and initializes a new priority queue.
 *
 * You should not modify this function.
 */
struct pq* pq_create() {
  struct pq* pq = malloc(sizeof(struct pq));
  assert(pq);
  pq->heap = dynarray_create(INITIAL_HEAP_CAPACITY);
  return pq;
}


/*
 * This function frees the memory associated with a priority queue.
 *
 * You should not modify this function.
 */
void pq_free(struct pq* pq) {
  assert(pq);
  while (!pq_isempty(pq)) {
    pq_remove_first(pq);
  }
  dynarray_free(pq->heap);
  free(pq);
}

/*
 * This function returns 1 if the given priority queue is empty or 0
 * otherwise.
 *
 * You should not modify this function.
 */
int pq_isempty(struct pq* pq) {
  assert(pq);
  return dynarray_size(pq->heap) == 0;
}

void swap(struct pq_elem * new_elem, struct pq_elem * change){
	struct pq_elem temp = *change;
	*change = *new_elem;
	*new_elem = temp;
}

void percolate_up(struct dynarray *heap, int idx) {
	if (idx != 0) {
		struct pq_elem * new_elem = dynarray_get(heap, idx);
		int new_pr = new_elem->priority;

		if (idx % 2 == 0) {
			struct pq_elem * change = dynarray_get(heap, (idx - 2) / 2);
			int change_pr = change->priority;

			if (change_pr > new_pr) {
				swap(dynarray_get(heap, idx), dynarray_get(heap, (idx - 2) / 2));
				idx = (idx - 2) / 2;
				percolate_up(heap, idx);

			}
		}

		else if (idx % 2 == 1) {
			struct pq_elem * change = dynarray_get(heap, (idx - 1) / 2);
			int change_pr = change->priority;

			if (change_pr > new_pr) {
				swap(dynarray_get(heap, idx), dynarray_get(heap, (idx - 1) / 2));
				idx = (idx - 1) / 2;
				percolate_up(heap, idx);
			}
		}
	}


}

void percolate_down(struct dynarray *heap, int idx) {
	int min_idx;
	int right_idx, left_idx;
	right_idx = (idx * 2) + 2;
	left_idx = (idx * 2) + 1;
	struct pq_elem* switching = dynarray_get(heap, idx);

	if (right_idx >= dynarray_size(heap) && left_idx >= dynarray_size(heap)) {
		return;
	}
	if (right_idx >= dynarray_size(heap) && left_idx < dynarray_size(heap)) {
		min_idx = left_idx;
	}

	if (right_idx < dynarray_size(heap)) {
    struct pq_elem* left_child = dynarray_get(heap, (idx * 2) + 1);
		struct pq_elem* right_child = dynarray_get(heap, (idx * 2) + 2);

		if (left_child->priority <= right_child->priority) {
		  min_idx = left_idx;
		}
		else {
			min_idx = right_idx;
		}
	}

	struct pq_elem * minimum = dynarray_get(heap, min_idx);

	if (switching->priority > minimum->priority) {
		swap(dynarray_get(heap, idx), dynarray_get(heap, min_idx));
		idx = min_idx;
		percolate_down(heap, idx);

	}
}

/*
 * This function inserts a new item with a specified priority into a priority
 * queue.
 *
 * You should complete the implementation of this function.  The first part
 * is done for, where a new element is created to be placed into the dynamic
 * array underlying the priority queue.
 */
void pq_insert(struct pq* pq, void* item, int priority) {
	assert(pq);
	/* FIXME: Complete this function */
	struct pq_elem* elem = malloc(sizeof(struct pq_elem));
	int idx = dynarray_size(pq->heap);
	elem->item = item;
	elem->priority = priority;
	dynarray_insert(pq->heap, -1, elem);
	percolate_up(pq->heap, idx);
}

  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the newly added element up in the heap array.  To
   * perform the percolation, you will have to compare the priority values of
   * the struct pq_elems in the heap array (i.e. by comparing the
   * elem->priority values).
   */


/*
 * This function returns the first (highest-priority) item from a priority
 * queue without removing it.
 *
 * You should complete the implementation of this function.
 */
void* pq_first(struct pq* pq) {
  assert(pq);
  assert(dynarray_size(pq->heap) > 0);
  /* FIXME: Complete this function */
  
  struct pq_elem * first = dynarray_get(pq->heap, 0);
  void * first_item = first->item;
  
  return first_item;
}


/*
 * This function removes the first (highest-priority) element from a priority
 * queue and returns its value.
 *
 * You should complete this function.
 */
void* pq_remove_first(struct pq* pq) {
	assert(pq);
	assert(dynarray_size(pq->heap) > 0);

	/* FIXME: Complete this function */
	if(dynarray_size(pq->heap) != 0){
 
    int last_idx = dynarray_size(pq->heap) - 1;
	  struct pq_elem* get_first = dynarray_get(pq->heap, 0);
	  void * item = get_first->item;

	  swap(dynarray_get(pq->heap, 0), dynarray_get(pq->heap, last_idx));
	  free(dynarray_get(pq->heap, last_idx));
	  dynarray_remove(pq->heap, last_idx);

	  if (dynarray_size(pq->heap) > 0) {
		  percolate_down(pq->heap, 0);
	  }
	  return item;
  } 
    return 0;
}
  /*
   * Determine what index in the heap array corresponds to the highest-priority
   * element (i.e. the one with the lowest priority value), and store the
   * value there in first_elem.
   */

  /*
   * Replace the highest-priority element with the appropriate one from within
   * the heap array.  Remove that replacement element from the array after
   * copying its value to the location of the old highest-priority element..
   */

  /*
   * Restore the heap so that it has the property that every node's priority
   * value is less than the priority values of its children.  This can be
   * done by "percolating" the element that replaced the highest-priority
   * element down in the heap array.  To perform the percolation, you will
   * have to compare the priority values of the struct pq_elems in the heap
   * array (i.e. by comparing the elem->priority values).  It may be helpful
   * to write a helper function to accomplish this percolation down.
   */

  /*
   * Return the extracted item, if the element taken out of the priority
   * queue is not NULL.
   */


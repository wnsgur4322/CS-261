/*
 * Name: Junhyeok Jeong
 * Email: jeongju@oregonstate.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/*
 create a new circular list deque
 
	pre:    none
 	post:	returns pointer to allocated deque q, q->Sentinel is allocated and q->size equals zero
 
 */

struct cirListDeque *createCirListDeque()
{
	/* FIXME: you must write this */
	struct cirListDeque *newList = malloc(sizeof(struct cirListDeque));
	
	newList->Sentinel = malloc(sizeof(struct DLink));
	assert(newList->Sentinel != 0);
	newList->Sentinel->next = newList->Sentinel;
	newList->Sentinel->prev = newList->Sentinel;
	newList->size = 0;

	return(newList);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
  struct DLink *newLink = malloc(sizeof(struct DLink));
  newLink->next = NULL;
  newLink->prev = NULL;
  newLink->value = val;
	/*temporary return value..you may need to change it*/
	return(newLink);	 

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
  assert(q);
  assert(lnk);
  
  struct DLink *addLink = _createLink(v);
  addLink->next = lnk->next;
  addLink->prev = lnk;
  addLink->next->prev = addLink;                
  addLink->prev->next = addLink;                  
  
  q->size++;  	 

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */	 
  assert(q);
  
  _addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	
  assert(q);
  
  _addLinkAfter(q, q->Sentinel, val); 

}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	/* FIXME: you must write this */
  assert(q);
  assert(q->size);
  
  TYPE Fvalue = q->Sentinel->next->value;	 
	/*temporary return value..you may need to change it*/
	return(Fvalue);
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
  assert(q);
  assert(q->size);
  
  TYPE Bvalue = q->Sentinel->prev->value;	 
	/*temporary return value..you may need to change it*/
	return(Bvalue);
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	 
  assert(q);
  assert(q->size);
  
  lnk->prev->next = lnk->next;
  lnk->next->prev = lnk->prev;
  
  lnk->next = NULL;
  lnk->prev = NULL;
  
  free(lnk);
  lnk = NULL;
  q->size--;
    
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
  
  assert(q);
  assert(q->size);
  TYPE removed = q->Sentinel->next->value;
    
  _removeLink(q, q->Sentinel->next);
  printf("Link %g has removed\n", removed); 
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */	 
  assert(q);
  assert(q->size);
  TYPE removed = q->Sentinel->prev->value;
  
  _removeLink(q, q->Sentinel->prev);
  printf("Link %g has removed\n", removed);  
}

/* De-allocate all links of the deque, and the deque itself

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	while(q->Sentinel != q->Sentinel->next){
   removeFrontCirListDeque(q);
   }
   
   free(q->Sentinel);
   free(q);
   q->size = 0;
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
  assert(q);
  
  if(q->size ==0){
    return 1;
    }
  else{
    return 0;
    }
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
  assert(q);
  assert(q->size);
  struct DLink *print = q->Sentinel->next;
  
  for(int i=0; i<q->size; i++){
    printf("%g  ", print->value);
    print = print->next;
  }    
	 printf("\n");
}

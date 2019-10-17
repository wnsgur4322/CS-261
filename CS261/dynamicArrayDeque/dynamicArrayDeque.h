/* 	dynArrDeque.h : Dynamic Array with Stack, Queue, Deque implementation. */

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1

#define TYPE int
#define EQ(a,b) (a == b)

typedef struct DynArr DynArr;

/* Dynamic Array Functions */
void initDynArr(DynArr *v, int capacity);
DynArr *createDynArr(int cap);

void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);

int sizeDynArr(DynArr *v);

/* Deque Interface */
void addFrontDynArr(DynArr *v, TYPE val);
void removeFrontDynArr(DynArr *v);
void addBackDynArr(DynArr *v, TYPE val);
void removeBackDynArr(DynArr *v);
TYPE frontDynArr(DynArr *v);
TYPE backDynArr(DynArr *v);

/* utility*/
void printDynArr(DynArr *v);

#endif

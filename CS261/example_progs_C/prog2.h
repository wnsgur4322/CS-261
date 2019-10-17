#ifndef _PROG2_H
#define _PROG2_H

#ifdef WIN32
#define MAX _max
#else
#define MAX max
#endif

#ifndef NULL
#define NULL 0
#endif
#define PI 3.14159

#define LT(a,b) (a > b ? 1 : 0)
/*
double x = 1.0;
double y = 0.5;
ptr = NULL;
LT(x,y);
*/
struct student{
  int ID;    /* 4 bytes */
  char name[10];  /* 10 -> 12 */
  char *name2;    /* 8 bytes */
};


int foo(float *);
#endif

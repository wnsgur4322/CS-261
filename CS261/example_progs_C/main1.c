#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog2.h"
#include "prog2.h"

/*int foo(float *);

struct student{
  int ID;    /* 4 bytes 
  char name[10];  /* 10 -> 12 
  char *name2;    /* 8 bytes 
};
*/
int main(int argc, char **argv)
{
   struct student Bob;
   struct student *new_students;

   float arr[3];
   double f1 = 0.04, f2 = 0.95;
   arr[0] = 0.2;
   arr[1] = 0.5;
   arr[2] = 0.3;
   foo(arr);
   printf("%d %d %d\n", LT(arr[0],arr[1]), LT(arr[1], arr[2]), LT(f1,f2));

   new_students = malloc(sizeof(struct student) * 10);
   new_students->ID = 5;
   printf("%d\n", (*new_students).ID);
  free(new_students); 

   Bob.ID = 5;
   strcpy(Bob.name, "Bob");
   Bob.name2 = "Bob";
/*   Bob.name = "Bob"; */

   printf("%d %s %s\n", Bob.ID, Bob.name, Bob.name2);
   printf("%d\n", sizeof(Bob));
   if (argc > 1)
   {
       printf("%s %s\n", argv[0], argv[1]);
       printf("%s\n", argv[1]);
   }
   return 0;
}

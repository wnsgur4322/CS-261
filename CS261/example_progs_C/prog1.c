#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(float *);

struct student{
  int ID;    /* 4 bytes */
  char name[10];  /* 10 -> 12 */
  char *name2;    /* 8 bytes */
};

int foo(float *bar)
{
   printf("%f %f\n", bar[0], bar[1]);
   return 1;
}

int main(int argc, char **argv)
{
   struct student Bob;
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

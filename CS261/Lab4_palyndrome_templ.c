#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define NUMBER_OF_STRINGS 5
#define STRING_LENGTH 100

/* struct definition of a node in the singly linked list */
struct Node {
  char value;
  struct Node* next;

};

/* struct definition of the stack */
struct Stack {
  struct Node* top;
};

/*checks if the stack is empty or not; returns 1 if empty and 0 if not*/
int isEmpty(struct Stack* stack)
{
  return (stack->top == NULL);
}

/*pushes a node with value (value) into stack*/
void push(struct Stack* stack, char value)
{
  /* complete me please */
}

/*pops (removes and returns) the top node from the stack*/
struct Node* pop(struct Stack* stack)
{
  /* complete me please*/
  return NULL;
}

void clear(struct Stack* stack){
  while(!isEmpty(stack)){
    pop(stack);
  }
}

/*reutrns 1 if s is palyndrome and 0 otherwise*/
int isPalyndrome(char* s, struct Stack* stack_a, struct Stack* stack_b, struct Stack* stack_c){
  clear(stack_a);
  clear(stack_b);
  clear(stack_c);
  
  /* complete me please*/

  return 1;
}

int main()
{
  struct Stack* stack_a = (struct Stack*) malloc(sizeof(struct Stack));
  struct Stack* stack_b = (struct Stack*) malloc(sizeof(struct Stack));
  struct Stack* stack_c = (struct Stack*) malloc(sizeof(struct Stack));
  
  assert(stack_a != NULL);
  assert(stack_b != NULL);
  assert(stack_c != NULL);
  
  char strs[NUMBER_OF_STRINGS][STRING_LENGTH+1] = {"was it a cat i saw", "madam", "level", "levels", "rotation"};
  int i;
  
  for(i=0; i<NUMBER_OF_STRINGS; ++i){
    int o = isPalyndrome(strs[i], stack_a, stack_b, stack_c);
    printf("string [%s] is [%s]\n", strs[i], o?"palyndrome":"not palyndrome");
  }
  
  free(stack_a);
  free(stack_b);
  free(stack_c);
  return 0;
}

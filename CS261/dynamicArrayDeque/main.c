#include <stdio.h>
#include <stdlib.h>
#include "dynamicArrayDeque.h"

int main (int argc, const char * argv[]) {

    struct DynArr *myDeque;


	myDeque =  createDynArr(3);

	addFrontDynArr(myDeque,7);
	printDynArr(myDeque);

	addBackDynArr(myDeque, 0);
	addBackDynArr(myDeque, 1);
	addBackDynArr(myDeque, 2);
	addBackDynArr(myDeque, 3);
	addFrontDynArr(myDeque,4);
	addFrontDynArr(myDeque, 5);
	removeFrontDynArr(myDeque);
	removeBackDynArr(myDeque);



	printDynArr(myDeque);
	return 0;
}

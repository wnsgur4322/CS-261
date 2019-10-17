#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	/* Try to write the tests yourself */
	struct cirListDeque* q = createCirListDeque();
	for(int i=0; i<3; i++){
	addBackCirListDeque(q, (TYPE)i+1);
	}
	for(int j=0; j<3; j++){
	addFrontCirListDeque(q, (TYPE)j+4);
	}

	addBackCirListDeque(q, (TYPE)7);
	addBackCirListDeque(q, (TYPE)8);

	printCirListDeque(q);

	printf("front link: %g\n", frontCirListDeque(q));
	printf("back link: %g\n", backCirListDeque(q));

	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);

	freeCirListDeque(q);
	printf("empty? %d\n", isEmptyCirListDeque(q));

	printf("Hello from test code!\n");
	return 0;
}



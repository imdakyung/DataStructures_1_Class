#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
int main() {

	arrayList* list = createArrayList(2);

	insertArrayList(list, 0, 10);
	insertArrayList(list, 1, 20);
	insertArrayList(list, 2, 30);
	insertArrayList(list, 3, 40);

	printArrayList(list);

	deleteArrayList(list, 1);

	printArrayList(list);

	printf("size=%d capacity=%d\n",
		sizeArrayList(list),
		list->capacity);

	destroyArrayList(list);

	return 0;
}
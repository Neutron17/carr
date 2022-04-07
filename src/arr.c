#include "arr.h"
#include <stdlib.h>
#include <stdio.h>

unsigned used;
unsigned max;

ArrErrors allocArr(Arr *arr, unsigned sz)  {
	//void **arrr = NULL;
	//arrr = (void**)malloc(1*sz);
	//arrr[0] = (void *)69;
	max = sz;
	arr->arr = (void **)malloc(sz);
	printf("%p\n", arr->arr);
	if(arr->arr == NULL) {
		printf("Couldn't allocate\n");
		return COULDNT_ALLOCATE;
	}
	used = 0;
	return SUCCESS;
}
ArrErrors allocArr_dtor(Arr *arr) {
	for(int i = 0; i < used; i++) {
		printf("Freeing %d. element\n", i);
		free(arr->arr[i]);
		arr->arr[i] = NULL;
	}
	free(arr->arr);
	arr->arr = NULL;
	printf("Successfuly freed all\n");
	return SUCCESS;
}
ArrErrors allocArr_add(Arr arr, void *n) {
	if(used == max)
		return MAX_ITEMS_REACHED;
	printf("%d\n", *((int*)n));
	printf("%p\n", arr.arr);

	arr.arr[used] = n;
	printf("Added %d. element\n", used+1);
	used++;
	return SUCCESS;
}

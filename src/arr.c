#include "arr.h"
#include <stdlib.h>
#include <stdio.h>

unsigned used;
unsigned max;

ArrErrors allocArr(Arr arr, unsigned sz)  {
	void **arrr = (void**)malloc(1*sz);
	if(arrr == NULL) {
		printf("Couldn't allocate\n");
		return COULDNT_ALLOCATE;
	}
	arrr[0] = (void *)69;
	max = sz;
	arr.arr = arrr;
	used = 0;
}
ArrErrors allocArr_dtor(Arr arr) {
	for(int i = 0; i < used; i++) {
		printf("Freeing %d. element\n", i);
		free(arr.arr[i]);
	}
	free(arr.arr);
	printf("Successfuly freed all\n");
}
ArrErrors allocArr_add(Arr arr, void *n) {
	if(used == max)
		return MAX_ITEMS_REACHED;
	printf("%d\n", *((int*)n));
	arr.arr[used] = n;
	printf("Added %d. element\n", used+1);
	used++;
}

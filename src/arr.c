#include "arr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

unsigned used;
unsigned max;

ArrErrors allocArr(Arr *arr, unsigned sz)  {
	//void **arrr = NULL;
	//arrr = (void**)malloc(1*sz);
	//arrr[0] = (void *)69;
	max = sz;
	arr->arr = (void **)malloc(sz);
	//printf("%p\n", arr->arr);
	if(arr->arr == NULL) {
        if(isDebug)
		    printf("Couldn't allocate\n");
		return COULDNT_ALLOCATE;
	}
	used = 0;
	return SUCCESS;
}
ArrErrors allocArr_dtor(Arr *arr) {
	if(isDebug)
		printf("dtor\n");
	for(int i = 0; i < used; i++) {
		printf("%p\n", arr->arr[i]);
        	if(isDebug) {
			printf("Freeing %d. element\n", 
					i+1);
		}
		free(arr->arr[i]);
		arr->arr[i] = NULL;
	}
	free(arr->arr);
	arr->arr = NULL;
	if(isDebug)
	    printf("Successfuly freed all\n");
	return SUCCESS;
}
ArrErrors allocArr_add(Arr arr, void *n) {
	if(used == max)
		return MAX_ITEMS_REACHED;
//	printf("%d\n", *((int*)n));
//	printf("%p\n", arr.arr);

	arr.arr[used] = n;
	if(isDebug)
	    printf("Added %d. element %p\n", used+1, n);
	used++;
	return SUCCESS;
}

ArrErrors allocArr_adds(Arr arr, void *n, ...) {
    va_list l;
    va_start(l, n);
    char last = SUCCESS;
    for(int i = 0; i < (int)n; i++) {
        if((last = allocArr_add(arr, va_arg(l, void *))) != SUCCESS)
            return last;
    }
    va_end(l);
    return SUCCESS;
}
bool allocArr_in(Arr arr, void *n) {
    for(int i = 0; i < used; i++) {
        if(arr.arr[i] == n)
            return true;
    }
    return false;
}
bool allocArr_ins(Arr arr, void *n, ...) {
    for(int i = 0; i < used; i++) {
        if(arr.arr[i] == n)
            return true;
    }
    return false;
}
ArrErrors allocArr_pop(Arr *arr, const int n) {
	free(arr->arr[used]);
	arr->arr[used] = NULL;
}

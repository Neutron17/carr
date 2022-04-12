#include "allocator.h"

void *alloc(Arr arr, size_t size) {
    void *x = malloc(size);
    if(x != NULL) {
    	allocArr_add(arr, x);
	printf("%p\n", x);
    }
    return x;
}

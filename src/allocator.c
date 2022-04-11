#include "allocator.h"

void *alloc(Arr arr, size_t size) {
    void *x = malloc(size);
    allocArr_add(arr, x);
    return x;
}
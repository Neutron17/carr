#ifndef _NTR_ALL_ARR_H_
#define _NTR_ALL_ARR_H_ 1

#include "allocator.h"
#include <stdbool.h>

typedef struct {
	void **arr;
} Arr;
typedef enum ArrErrors {
	SUCCESS = 0,
	COULDNT_ALLOCATE,
	MAX_ITEMS_REACHED,
	UNDEFINED_ERROR,
    UNKNOWN_PTR
} ArrErrors;

extern bool isDebug;

ArrErrors allocArr     (Arr *arr, unsigned sz);
ArrErrors allocArr_dtor(Arr *arr);
ArrErrors allocArr_add (Arr arr, void *n);
ArrErrors allocArr_adds(Arr arr, void *n, ...);
bool      allocArr_in  (Arr arr, void *n);
bool      allocArr_ins (Arr arr, void *n, ...);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

bool isDebug = true;
//-DNTR_ALL_ARR_NO_CONSTS 1
int main(int argc, const char *argv[]) {
#ifdef NTR_ALL_ARR_NO_CONSTS
    Arr arr;
    allocArr(&arr, 3);
#endif
	int *x, *y, *z;

#ifdef NTR_ALL_ARR_NO_CONSTS
    x = (int*) alloc(arr, sizeof(int));
    y = (int*) alloc(arr, sizeof(int));
    z = (int*) alloc(arr, sizeof(int));
#else
    x = (int*) alloc(sizeof(int));
    y = (int*) alloc(sizeof(int));
    z = (int*) alloc(sizeof(int));
#endif
	*x = 69;
	*y = 70;
	*z = 2;
    allocArr_pop(&arr);
#ifdef NTR_ALL_ARR_NO_CONSTS
    allocArr_dtor(&arr);
#endif
	return EXIT_SUCCESS;
}

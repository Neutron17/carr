#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
#include "allocator.h"

bool isDebug = true;

int main(int argc, const char *argv[]) {
	Arr arr;
	allocArr(&arr, 3);
	int *x, *y, *z;
	x = (int*)alloc(arr, sizeof(int));
	y = (int*)alloc(arr, sizeof(int));
	z = (int*)alloc(arr, sizeof(int));
	*x = 69;
	*y = 70;
	*z = 2;
    //allocArr_adds(arr, (void *)3, x,y,z);

/*	allocArr_add(arr, (void *)x);
	allocArr_add(arr, (void *)y);
	allocArr_add(arr, (void *)z);*/
	allocArr_dtor(&arr);
	return EXIT_SUCCESS;
}

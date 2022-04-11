#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

bool isDebug = false;

int main(int argc, const char *argv[]) {
	Arr arr;
	allocArr(&arr, 3);
	int *x, *y, *z;
	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	z = malloc(sizeof(int));
	*x = 69;
	*y = 70;
    *z = 2;
    allocArr_adds(arr, (void *)3, x,y,z);

/*	allocArr_add(arr, (void *)x);
	allocArr_add(arr, (void *)y);
	allocArr_add(arr, (void *)z);*/
	allocArr_dtor(&arr);
	return EXIT_SUCCESS;
}

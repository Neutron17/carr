#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

int main(int argc, const char *argv[]) {
	Arr arr;
	allocArr(arr, 3);
	int *x, *y, *z;
	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	z = malloc(sizeof(int));
	allocArr_add(arr, (void *)x);
	allocArr_add(arr, (void *)y);
	allocArr_add(arr, (void *)z);
	allocArr_dtor(arr);
	return EXIT_SUCCESS;
}

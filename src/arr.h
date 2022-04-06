#ifndef _NTR_ALL_ARR_H_
#define _NTR_ALL_ARR_H_ 1

typedef struct {
	void **arr;
} Arr;
typedef enum ArrErrors {
	SUCCESS = 0,
	COULDNT_ALLOCATE,
	MAX_ITEMS_REACHED,
	UNDEFINED_ERROR
} ArrErrors;

ArrErrors allocArr/*_ctor*/(Arr arr, unsigned sz);
ArrErrors allocArr_dtor(Arr arr);
ArrErrors allocArr_add(Arr arr, void *n);
ArrErrors allocArr_adds(Arr arr, void *n, ...);
ArrErrors dallocArr_rem(Arr arr, void *n);
ArrErrors allocArr_rems(Arr arr, void *n, ...);

#endif

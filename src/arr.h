#ifndef _NTR_ALL_ARR_H_
#define _NTR_ALL_ARR_H_ 1

//#include "allocator.h"
#include <stdbool.h>
#include <stdlib.h>

#define ARR_SIZE 5

typedef struct {
    void **arr;
} Arr;

// Return values
enum ArrErrors {
	SUCCESS = 0,
	COULDNT_ALLOCATE,
	MAX_ITEMS_REACHED,
    SHR,
    SHR_FREE,
    INC,
    SAME_SZ
};

extern bool isDebug;

#ifndef NTR_ALL_ARR_NO_CONSTS
    // Malloc copy
    void *alloc(size_t size);
    // Constructor
    __attribute__((used)) enum ArrErrors __attribute__((constructor)) __allocArr_ctor();
    // Destructor
    __attribute__((used)) enum ArrErrors __attribute__((destructor)) __allocArr_dtor();
    // Control methods
    enum ArrErrors  allocArr_add (void *n);
    enum ArrErrors  allocArr_adds(void *n, ...);
    bool            allocArr_in  (const void *n);
    bool            allocArr_ins (const void *n, ...);
    // Overloading stuff
    #define __NARGS(...) __NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
    #define __NARGS_(_5, _4, _3, _2, _1, N, ...) N
    #define __CONC(A, B) __CONC_(A, B)
    #define __CONC_(A, B) A##B
    #define allocArr_pop(...) __CONC(__allocArr_pop, __NARGS(__VA_ARGS__))(__VA_ARGS__)
    enum ArrErrors __allocArr_pop1();
    enum ArrErrors __allocArr_pop2(int n);
#else
void *alloc(Arr arr, size_t size);

// Constructor
__attribute__((used)) enum ArrErrors allocArr(Arr *arr, unsigned size);
// Destructor
__attribute__((used)) enum ArrErrors allocArr_dtor(Arr *arr);

enum ArrErrors allocArr_add (Arr arr, void *n);
enum ArrErrors allocArr_adds(Arr arr, void *n, ...);
bool      allocArr_in  (Arr arr, void *n);
bool      allocArr_ins (Arr arr, void *n, ...);
// Overloading stuff
#define __NARGS(...) __NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define __NARGS_(_5, _4, _3, _2, _1, N, ...) N
#define __CONC(A, B) __CONC_(A, B)
#define __CONC_(A, B) A##B
#define allocArr_pop(...) __CONC(__allocArr_pop, __NARGS(__VA_ARGS__))(__VA_ARGS__)
enum ArrErrors __allocArr_pop1(Arr *arr);
enum ArrErrors __allocArr_pop2(Arr *arr, const int n);
#endif //
#endif // _NTR_....
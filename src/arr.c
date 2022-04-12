#include "arr.h"
#include <stdio.h>
#include <stdarg.h>

unsigned used;
unsigned max;
#ifndef NTR_ALL_ARR_NO_CONSTS
    Arr arr;
    void *alloc(size_t size) {
        void *x = malloc(size);
        if(x != NULL) {
            allocArr_add(x);
            printf("%p\n", x);
        }
        return x;
    }
    enum ArrErrors resize(size_t size) {
        if(size == max)
            return SAME_SZ;
        if(size < max) {
            if (size > used) {
                for(int i = 0; i < size - used; i++) {

                }
                arr.arr = realloc(arr.arr, size);
                return SHR_FREE;
            }
            return SHR;
        }
        return INC;
    }

    __attribute__((used)) enum ArrErrors __allocArr_ctor() {
        //void **arrr = NULL;
        //arrr = (void**)malloc(1*sz);
        //arrr[0] = (void *)69;
        max = ARR_SIZE;
        arr.arr = (void **)malloc(ARR_SIZE);
        //printf("%p\n", arr->arr);
        if(arr.arr == NULL) {
            if(isDebug)
                printf("Couldn't allocate\n");
            return COULDNT_ALLOCATE;
        }
        used = 0;
        return SUCCESS;
    }
    __attribute__((used)) enum ArrErrors __allocArr_dtor() {
        if(isDebug)
            printf("dtor\n");
        for(int i = 0; i < used; i++) {
            printf("%p\n", arr.arr[i]);
                if(isDebug) {
                printf("Freeing %d. element\n",
                        i+1);
            }
            free(arr.arr[i]);
            arr.arr[i] = NULL;
        }
        free(arr.arr);
        arr.arr = NULL;
        if(isDebug)
            printf("Successfuly freed all\n");
        return SUCCESS;
    }
    enum ArrErrors allocArr_add(void *n) {
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
    enum ArrErrors allocArr_adds(void *n, ...) {
        va_list l;
        va_start(l, n);
        char last = SUCCESS;
        for(int i = 0; i < (int)n; i++) {
            if((last = allocArr_add(va_arg(l, void *))) != SUCCESS)
                return last;
        }
        va_end(l);
        return SUCCESS;
    }
    enum ArrErrors __allocArr_pop2(const int n) {
        for(int i = 0; i < n; i++)
            __allocArr_pop1();
    }
    enum ArrErrors __allocArr_pop1() {
        free(arr.arr[used - 1]);
        arr.arr[used - 1] = NULL;
        used--;
    }
    bool allocArr_in(const void *n) {
        for(int i = 0; i < used; i++) {
            if(arr.arr[i] == n)
                return true;
        }
        return false;
    }
    // TODO: implement with vararg
     bool allocArr_ins(const void *n, ...) {
        for(int i = 0; i < used; i++) {
            if(arr.arr[i] == n)
                return true;
        }
        return false;
    }
#else
    void *alloc(Arr arr, size_t size) {
        void *x = malloc(size);
        allocArr_add(arr, x);
        return x;
    }
    enum ArrErrors allocArr(Arr *arr, unsigned sz)  {
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
    enum ArrErrors allocArr_dtor(Arr *arr) {
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
    enum ArrErrors allocArr_add(Arr arr, void *n) {
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

    enum ArrErrors allocArr_adds(Arr arr, void *n, ...) {
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
    enum ArrErrors __allocArr_pop1(Arr *arr) {
        free(arr->arr[used - 1]);
        arr->arr[used - 1] = NULL;
        used--;
    }
    enum ArrErrors __allocArr_pop2(Arr *arr, const int n) {
        for(int i = 0; i < n; i++)
            __allocArr_pop1(arr);
    }
#endif
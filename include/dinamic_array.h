#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct
{
    int *arr;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *new_dynamic_array(int capacity);
int da_size(DynamicArray *dynamic_array);
int da_capacity(DynamicArray *dynamic_array);
bool da_is_empty(DynamicArray *dynamic_array);
int da_at(DynamicArray *dynamic_array, int index);
void da_push(DynamicArray *dynamic_array, int value);
void da_insert(DynamicArray *dynamic_array, int index, int value);
void da_prepend(DynamicArray *dynamic_array, int value);
int da_pop(DynamicArray *dynamic_array);
void da_delete(DynamicArray *dynamic_array, int index);
void check_pointer(void *p);
void da_remove(DynamicArray *dynamic_array, int value);
int da_find(DynamicArray *dynamic_array, int value);
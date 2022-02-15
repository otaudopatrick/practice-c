#include <stdbool.h>
typedef struct ImplementationArray {
  int size;
  int capacity;
  int *data;
} DSArray;

DSArray* array_new(int capacity);
int array_size(DSArray* arr);
int array_capacity(DSArray* arr);
bool array_is_empty(DSArray* arr);
int array_at(DSArray* arr, int index);
void array_push(DSArray* arr, int item);
void check_pointer(void *p);
void array_print(DSArray* arr);
void array_insert(DSArray* arr, int index, int item);
void array_prepend(DSArray* arr,int item);
int array_pop(DSArray* arr);

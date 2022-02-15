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
void check_pointer(void *p);

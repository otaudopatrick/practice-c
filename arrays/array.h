typedef struct ImplementationArray {
  int size;
  int capacity;
  int *data;
} DSArray;

DSArray* array_new(int capacity);
int array_size(DSArray* arr);
int array_capacity(DSArray* arr);

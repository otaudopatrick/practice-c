#include <stdio.h>
#include <stdlib.h>
#include "./array.h"

DSArray *array_new(int capacity){
  DSArray *arr =  malloc(sizeof(DSArray));
  
  if(arr == NULL) {
    abort();
  }

  arr->size = 0;
  arr->capacity = capacity;
  arr->data = (int *) malloc(sizeof(int) * capacity);

  if(arr->data == NULL) {
    abort();
  }

  return arr;
}

int array_size(DSArray* arr) {
  if(arr == NULL) {
    abort();
  }
  return arr->size;
}

int array_capacity(DSArray* arr) {
  if(arr == NULL){
    abort();
  }
  return arr->capacity;
}

bool array_is_empty(DSArray* arr) {
  if(arr == NULL) {
    abort();
  }
  if(arr->size == 0) return true;
  return false; 
}

void main() {
  DSArray* arr = array_new(10);
  printf("%i",array_is_empty(arr));
}
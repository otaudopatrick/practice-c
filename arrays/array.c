#include <stdio.h>
#include <stdlib.h>
#include "./array.h"

DSArray *array_new(int capacity){
  DSArray *arr =  malloc(sizeof(DSArray));
  check_pointer(arr);
  arr->size = 0;
  arr->capacity = capacity;
  arr->data = (int *) malloc(sizeof(int) * capacity);
  check_pointer(arr->data);
  return arr;
}

int array_size(DSArray* arr) {
  check_pointer(arr);
  return arr->size;
}

int array_capacity(DSArray* arr) {
  check_pointer(arr);
  return arr->capacity;
}

bool array_is_empty(DSArray* arr) {
  check_pointer(arr);
  if(arr->size == 0) return true;
  return false; 
}

int array_at(DSArray* arr, int index){
  check_pointer(arr);
  if(index > arr->size - 1 || index < 0 ) abort();
  return arr->data[index];
}
void array_push(DSArray* arr, int item) {
  check_pointer(arr);
  if(array_size(arr) < array_capacity(arr) ){
    *(arr->data + arr->size ) = item;
    ++(arr->size);
  }
}
void array_print(DSArray* arr) {
  printf("Capacity: %d\n", arr->capacity);
  printf("Size: %d\n", arr->size);
  printf("[ ");
  for ( int i = 0; i < arr->size; i++)
  {
    if(i!=0){
      printf(" , ");
    }
    printf("%d",*(arr->data + i));
    
  }
  printf(" ]");
  
}
void check_pointer(void *p) {
  if(p == NULL){
    abort();
  }
}
void main() {
  DSArray* arr = array_new(10);
  array_push(arr, 10);
  array_push(arr, 11);
  array_print(arr);
}
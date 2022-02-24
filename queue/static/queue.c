#include <stdio.h>
#include <stdlib.h>
#include "./queue.h"

struct dsqueue
{
  int size, head, tail;
  int data[MAX];
};


DSqueue* queue_create() {
  DSqueue* queue = (DSqueue*) malloc(sizeof(DSqueue));
  if(queue == NULL) 
    abort();
  else
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
  return queue;
}

void queue_free(DSqueue* queue) {
  free(queue);
}

int queue_size(DSqueue* queue) {
  check_pointer(queue);
  return queue->size;
}

int queue_is_full(DSqueue* queue) {
  check_pointer(queue);
  if(queue->size == MAX) return 1;
  return 0;
}

int queue_is_empty(DSqueue* queue) {
  check_pointer(queue);
  if(queue->size == 0) return 1;
  return 0;
}

int  queue_enqueue(DSqueue* queue, int value) {
  check_pointer(queue);
  if(queue_is_full(queue)) return 0;
  queue->data[queue->tail] = value;
  queue->tail++;
  queue->size++;
  return 1;
}

void check_pointer(void *p){
  if(p == NULL) abort();
}

void main(){
  DSqueue* queue = queue_create();
  queue_enqueue(queue,1);
  queue_enqueue(queue,3);
}
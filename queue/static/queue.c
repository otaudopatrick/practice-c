#include <stdio.h>
#include <stdlib.h>
#include "./queue.h"

struct dsqueue
{
  int size, head, tail;
  int data[];
};


DSqueue* queue_create() {
  DSqueue* queue = (DSqueue*) malloc(sizeof(DSqueue));
  if(queue == NULL) 
    abort();
  else
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->data[MAX];
  return queue;
}

void queue_free(DSqueue* queue) {
  free(queue);
}

int queue_size(DSqueue* queue) {
  check_pointer(queue);
  return queue->size;
}

void check_pointer(void *p){
  if(p == NULL) abort();
}

void main(){
  DSqueue* queue = queue_create();
  queue_free(queue);
}
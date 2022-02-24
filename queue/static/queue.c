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
  if((queue->size + 1 ) == MAX ) return 0;
  queue->data[queue->tail] = value;
  queue->tail = (queue->tail + 1) % MAX;
  queue->size++;
  return 1;
}

int  queue_denqueue(DSqueue* queue){
  check_pointer(queue);
  if(queue_is_empty(queue)) return 0;
  queue->head = (queue->head + 1) % MAX;
  queue->size--;
  return 1;
}
void queue_print(DSqueue* queue) {
  check_pointer(queue);
  printf("\n");
  if(queue->tail >= queue->head) {
    for (int i = queue->head; i <= queue->tail-1 ; i++)
      printf(" <- %d ", queue->data[i]);
  }
  else {
    for (int i = queue->head; i <= (MAX-1); i++)
      printf(" <- %d ", queue->data[i]);
 
    for (int i = 0; i <= (queue->tail -1); i++)
      printf(" <- %d ", queue->data[i]);
  }
}


void check_pointer(void *p){
  if(p == NULL) abort();
}

void main(){
  DSqueue* queue = queue_create();
  queue_enqueue(queue,1);
  queue_enqueue(queue,3);
  queue_enqueue(queue,4);
  queue_enqueue(queue,5);
  queue_enqueue(queue,6);
  queue_enqueue(queue,7);
  queue_enqueue(queue,8);
  queue_enqueue(queue,9);
  queue_enqueue(queue,0);
  queue_enqueue(queue,12);
  queue_enqueue(queue,13);
  queue_enqueue(queue,14);
  queue_enqueue(queue,15);
  queue_enqueue(queue,16);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_enqueue(queue,17);
  queue_enqueue(queue,35);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_denqueue(queue);
  queue_enqueue(queue,10);
  queue_enqueue(queue,24);
  queue_enqueue(queue,26);
  printf("Queue size: %d\n", queue->size);
  printf("Queue head: %d\n", queue->head);
  printf("Queue tail: %d\n", queue->tail);
  queue_print(queue);
}
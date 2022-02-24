#include <stdlib.h>
#include <stdio.h>
#include "./queue.h"

struct node
{
  int data;
  struct Node* next;
};

struct dsqueue {
  struct Node* head;
  struct Node* tail;
};

DSQueue* queue_create() {
  DSQueue* queue = (DSQueue*) malloc(sizeof(DSQueue));
  if(queue != NULL) {
    queue->head = NULL;
    queue->tail = NULL;
  }
  return queue;
}

void main(){
  DSQueue* queue = queue_create();
}
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
void queue_free(DSQueue* queue) {
  if(queue->head != NULL) {
    Node* node = queue->head;
    queue->head = node->next;
    free(node);
  }
  free(queue);
}
void main(){
  DSQueue* queue = queue_create();
}
#include <stdlib.h>
#include <stdio.h>
#include "./queue.h"

struct dsqueue {
  struct node *head;
  struct node *tail;
};
struct node
{
  int data;
  struct node *next;
};
typedef struct node Node;


DSQueue* queue_create() {
  DSQueue* queue = (DSQueue*) malloc(sizeof(DSQueue));
  if(queue != NULL) {
    queue->head = NULL;
    queue->tail = NULL;
  }
  return queue;
}
void queue_free(DSQueue* queue) {
  if(queue != NULL) {
    Node* node;
    while (queue->head != NULL)
    {  
      node = queue->head;
      queue->head = node->next;
      free(node);
    }
  }
  free(queue);
}
int queue_size(DSQueue* queue) {
  if(queue != NULL) {
    Node*  node = queue->head;
    while (node != NULL)
    {
      node = node->next;
    }
  }
  return 0;
}
int queue_is_full(DSQueue* queue) {
  if(queue != NULL) return 0;
  return -1;
}
int queue_is_empty(DSQueue* queue) {
  if(queue != NULL) return -1 ;
  return (queue->head == NULL);
}
void main(){
  DSQueue* queue = queue_create();
  printf("Queue size: %d ",queue_size(queue));
}
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
  if(queue == NULL) return -1;
  int count = 0;
  Node*  node = queue->head;
  while (node != NULL)
  {
    count++;
    node = node->next;
  }
  return count;
}
int queue_is_full(DSQueue* queue) {
  if(queue != NULL) return 0;
  return -1;
}
int queue_is_empty(DSQueue* queue) {
  if(queue != NULL) return -1 ;
  return (queue->head == NULL);
}

int  queue_enqueue(DSQueue* queue, int value) {
  if(queue == NULL) return -1;
  Node* node = (Node*) malloc(sizeof(Node));
  if(node == NULL) return -1;
  node->data = value;
  node->next = NULL;
  if(queue->head == NULL) {
    queue->head = node;
  }else{
    queue->tail->next = node;
  }
  queue->tail = node;
  return 1;
}

int  queue_denqueue(DSQueue* queue) {
  if(queue == NULL) -1;
  Node* node = queue->head;
  queue->head = node->next;
  free(node);
}
void main(){
  DSQueue* queue = queue_create();
  queue_enqueue(queue, 10);
  queue_enqueue(queue, 30);
  queue_enqueue(queue, 2310);
  queue_denqueue(queue);
  queue_enqueue(queue, 1123123);
  printf("Queue size: %d ",queue_size(queue));
}
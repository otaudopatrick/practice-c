#include <stdlib.h>
#include <stdio.h>
#include "./list.h"

struct node
{
  int data;
  struct node* next;
};

typedef  struct  node Node;

DSList* list_create() {
  DSList* list = (DSList*) malloc(sizeof(DSList));
  if(list != NULL)  {
    (*list)  = NULL;
  }
  return list;
}
void queue_free(DSList* list) {
  if(list != NULL) {

    while ( (*list)  != NULL)
    {
      Node* node = (*list);
      (*list) = node->next;
      free(node);
    }
    free(list);
  }
}

int list_size(DSList* list) {
  if(list == NULL) return -1;
  int count = 0;
  Node* node= (*list);
  while (node != NULL)
  {
    count++;
    node = node->next;
  }
  return count;
}
int list_empty(DSList* list) {
  if(list == NULL) return  -1;
  if(*list == NULL) return 1;
  return 0;
}
Node* create_node(int value) {
  Node* node = (Node*) malloc(sizeof(Node));
  if(node !=  NULL) {
    node->data = value;
    node->next = NULL;
    return node;
  }
}
int list_push_front(DSList* list, int value) {
  if(list == NULL)  return -1;
  Node* node  = create_node(value);
  if((*list) == NULL) {
    (*list) = node;
  }else {
    node->next =(*list);
    (*list)  = node;
  }
  return 1;
}
int list_push_back(DSList* list, int value) {
  if(list == NULL)  return -1;
  Node* node  = create_node(value);
  Node* aux  = (*list);
  while (aux->next != NULL)
  {
    aux = aux ->next;
  }
  aux->next = node;
  return 1;
}

void main()
{
  DSList* list = list_create();
  list_push_front(list, 10);
  list_push_front(list, 39);
  list_push_back(list, 234);
  list_push_back(list, 591);
  int c = list_size(list);
}


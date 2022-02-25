#include <stdlib.h>
#include <stdio.h>
#include "./list.h"

struct node
{
  int data;
  struct node* next;
};

typedef  struct  node Node;
Node* get_node_back(DSList* list);

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
int list_pop_back(DSList* list) {
  if(list == NULL) abort();
  if((*list)  ==  NULL) abort();
  int value;
  Node *previous, *node = (*list);
  while (node->next != NULL)
  {
    previous =  node;
    node = node->next;
  }
  value = node->data;
  if(node == (*list)) {
    *list = node->next;
  }
  else  {
    previous->next = node->next;
  }
  free(node);
  return value;
}

int list_front(DSList* list) {
  if(list ==  NULL) abort();
  return (*list)->data;
}
int list_back(DSList* list) {
  if(list ==  NULL) abort();
   Node* node= get_node_back(list);
   return node->data;
}
int list_insert(DSList* list, int index, int value) {
  if(list== NULL) abort();
  if(index > (list_size(list)- 1)) abort();
  int count = 0;
  Node *previous, *node = (*list);
  while (count!=index)
  {
    previous =  node;
    node = node->next;
    count++;
  }
  Node* newNode = create_node(value);
  if(node == (*list)) {
    newNode->next = (*list);
    (*list) = newNode;
  }else {
    previous->next = newNode;
    newNode->next = node;
  }
  return 1;
}

Node* get_node_back(DSList* list) {
  if(list == NULL) abort;
  Node* aux  = (*list);
  while (aux->next != NULL)
  {
    aux = aux ->next;
  }
  return aux;
}

void main()
{
  DSList* list = list_create();
  list_push_front(list, 10);
  list_push_front(list, 39);
  list_push_back(list, 234);
  list_push_back(list, 591);
  list_pop_back(list);
  int c = list_size(list);
  int d = list_front(list);
  int e = list_back(list);
  list_insert(list,0, 78);
  printf("List size: %d ", list_size(list));
}


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
void main()
{
  DSList* list = list_create();
  queue_free(list);
}


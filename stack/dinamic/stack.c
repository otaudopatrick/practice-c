#include <stdlib.h>
#include <stdio.h>
#include "./stack.h"

struct element
{
  int  data;
  struct element  *next;
};

typedef  struct element Elem;

DSStack* stack_create() {
  DSStack* st = (DSStack*) malloc(sizeof(DSStack));
  if(st != NULL) {
    *st = NULL;
  }
  return st;
}

void stack_free(DSStack* st) {
  if(st != NULL) {
    Elem* node;
    while ((*st) !=NULL) {
      node = *st;
      *st = (*st)->next;
      free(node);
    }
    free(st);
  }
}
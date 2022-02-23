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

int stack_size(DSStack* st){
  if(st == NULL) return -1;
  int count = 0;
  while ((*st) != NULL){
    count++;
    *st = (*st)->next;
  }
  return count;
}

int stack_is_full(DSStack* st) {
  if(st == NULL) return -1;
  return 0;
}

int stack_is_empty(DSStack* st) {
  if(st == NULL)  return  -1;
  if((*st) == NULL) return 1;
  return 0;
}

int stack_push(DSStack* st, int value) {
  if(st == NULL) return -1;
  if(stack_is_full(st)) return 0;
  Elem* node = (Elem*) malloc(sizeof(Elem));
  node->data = value;
  node->next = (*st)->next;
  (*st)->next = node;
}
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
  Elem* node = (*st);
  while (node != NULL){
    count++;
    node = node->next;
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
  if(st == NULL) return 0;
  Elem* node = (Elem*) malloc(sizeof(Elem));
  if(node == NULL) return 0;
  node->data = value;
  node->next = (*st);
  *st = node;
  return 1;
}

int stack_pop(DSStack* st) {
 if(st == NULL) return -1;
 if((*st) == NULL) return 0; 
 Elem* node = *st;
 *st = node->next;
 free(node);
 return 1;
}

void stack_print(DSStack* st) {
  Elem* node = (*st);
  while ( node != NULL){
    printf("%d\n", node->data);
    node = node->next;
  }
}

void main() {
  
  DSStack* st = stack_create();
  stack_push(st, 10);
  stack_push(st, 32);
  stack_push(st, 5342);
  printf("Stack size: %d\n", stack_size(st));
  stack_print(st);
}
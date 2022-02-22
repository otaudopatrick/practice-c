#include <stdlib.h>
#include "./stack.h"

struct dsstack {
  int qtd;
  int data[MAX];
};

DSStack* stack_create() {
  DSStack* st;
  st = (DSStack*) malloc(sizeof(struct dsstack));
  if(st != NULL) {
    st->qtd = 0;
  }
  return st;
}

void stack_free(DSStack* st){
    free(st);
}
int stack_size(DSStack* st) {
  if(st == NULL)
    return -1;
  else
    return st->qtd;
}

int stack_is_full(DSStack* st) {
  if(st == NULL) 
    return -1;
  else
    return (st->qtd == MAX);
}
int stack_is_empty(DSStack* st) {
  if(st == NULL) 
    return -1;
  else
    return (st->qtd == 0);
}

int stack_push(DSStack* st, int value) {
  if(st == NULL) return 0;
  if(stack_is_full(st)) return 0;
  st->data[st->qtd] = value;
  st->qtd ++;
  return 1;
}
#include <stdlib.h>
#include <stdio.h>
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
int stack_pop(DSStack* st) {
  if(st == NULL || st->qtd == 0) {
    return 0;
  }
  st->qtd--;
  return 1;
}
void stack_print(DSStack* st) {
  if(st  == NULL) abort();

  for (int i = st->qtd - 1; i >= 0; i--)
  {
    printf("|   %d   |\n", st->data[i]);
    if(i == 0) {
      printf("_________");
    }
  }
  
}

void main () {
  DSStack* st = stack_create();
  stack_push(st,5);
  stack_push(st,62);
  stack_push(st,43);
  stack_push(st,83);
  stack_push(st,9);
  stack_print(st);
}
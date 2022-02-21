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
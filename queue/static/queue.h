#include <stdbool.h>
#define MAX 15
typedef struct dsqueue DSqueue;

DSqueue* queue_create();
void queue_free(DSqueue* queue);
int queue_size(DSqueue* queue);
int queue_is_full(DSqueue* queue);
int queue_is_empty(DSqueue* queue);
int  queue_enqueue(DSqueue* queue, int value);
int  queue_denqueue(DSqueue* queue);
void queue_print(DSqueue* queue);
void check_pointer(void *p);
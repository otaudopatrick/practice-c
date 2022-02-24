#include <stdbool.h>
#define MAX 10
typedef struct dsqueue DSqueue;

DSqueue* queue_create();
void queue_free(DSqueue* queue);
int queue_size(DSqueue* queue);
int queue_is_full(DSqueue* queue);
int queue_is_empty(DSqueue* queue);
void check_pointer(void *p);
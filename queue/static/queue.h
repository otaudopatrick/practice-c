#define MAX 10
typedef struct dsqueue DSqueue;

DSqueue* queue_create();
void queue_free(DSqueue* queue);
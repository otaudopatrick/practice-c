typedef struct dsqueue DSQueue;

DSQueue* queue_create();
void queue_free(DSQueue* queue);
int queue_size(DSQueue* queue);
int queue_is_full(DSQueue* queue);
int queue_is_empty(DSQueue* queue);
int  queue_enqueue(DSQueue* queue, int value);
int  queue_denqueue(DSQueue* queue);
void queue_print(DSQueue* queue);

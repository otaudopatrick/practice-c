typedef struct  node* DSList;

DSList* list_create();
void queue_free(DSList* list);
int list_size(DSList* list);
int list_empty(DSList* list);

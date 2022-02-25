typedef struct  node* DSList;

DSList* list_create();
void queue_free(DSList* list);
int list_size(DSList* list);
int list_empty(DSList* list);
int list_push_front(DSList* list, int value);
int list_push_back(DSList* list, int value);
int list_pop_back(DSList* list);
int list_front(DSList* list);
int list_back(DSList* list);
int list_insert(DSList* list, int index, int value);
int list_erase(DSList* list, int index);
#define MAX 100

typedef struct dsstack DSStack;

DSStack* stack_create();
void stack_free(DSStack* st);
int stack_size(DSStack* st);
int stack_is_full(DSStack* st);
int stack_is_empty(DSStack* st);
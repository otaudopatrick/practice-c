#define MAX 100
 typedef struct dsstack DSStack;

DSStack* stack_create();
void stack_free(DSStack* st);
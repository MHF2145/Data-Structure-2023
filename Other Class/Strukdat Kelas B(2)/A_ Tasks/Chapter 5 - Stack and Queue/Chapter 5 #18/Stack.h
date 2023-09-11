#define MAX_SIZE 500

typedef struct stack_t {
    int data[MAX_SIZE];
    int size;
} Stack;

void st_init(Stack* stack);
void st_push(Stack* stack, int data);
int st_pop(Stack* stack);
int st_top(Stack* stack);
int st_empty(Stack* stack);
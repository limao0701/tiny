typedef struct array_stack{
        struct array_stack * self;
        int size;
        int *botom;
        int *top;
        int (*stack_push)(struct array_stack*stack,int value);
        int (*stack_pop)(struct array_stack*stack);
        int (*stack_isempty)(struct array_stack*stack);
        int (*stack_top)(struct array_stack*stack);
}array_stack;

int array_stack_isempty(array_stack * stack);
int array_stack_push(array_stack *stack,int value);
int array_stack_pop(array_stack *stack);
array_stack *array_stack_new(int size);
int array_stack_destroy(array_stack* stack);
int stack_top(struct array_stack*stack);

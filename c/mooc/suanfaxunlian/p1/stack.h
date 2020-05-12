#include "queue.h"

typedef struct array_stack{
        struct array_stack * self;
        int size;
        char **botom;
        char **top;
        int (*push)(struct array_stack*stack,char* value);
        char *(*pop)(struct array_stack*stack);
        int (*isempty)(struct array_stack*stack);
        char *(*get_top)(struct array_stack*stack);
}array_stack;

int array_stack_isempty(array_stack * stack);
int array_stack_push(array_stack *stack,char* value);
char *array_stack_pop(array_stack *stack);
array_stack *array_stack_new(int size);
int array_stack_destroy(array_stack* stack);
char *stack_top(struct array_stack*stack);


typedef struct bin_node_stack{
        struct bin_node_stack * self;
        int size;
        bin_node **botom;
        bin_node **top;
        int (*push)(struct bin_node_stack *stack,bin_node* node);
        bin_node *(*pop)(struct bin_node_stack *stack);
        int (*isempty)(struct bin_node_stack *stack);
        int (*isfull)(struct bin_node_stack *stack);
        bin_node *(*get_top)(struct bin_node_stack *stack);
}bin_node_stack;

bin_node_stack *bin_node_stack_new(int size);
int bin_node_stack_isempty(bin_node_stack * stack);
int bin_node_stack_isfull(bin_node_stack*stack);
int bin_node_stack_push(bin_node_stack *stack,bin_node* value);
bin_node *bin_node_stack_pop(bin_node_stack *stack);
int bin_node_stack_destroy(bin_node_stack* stack);
bin_node *bin_node_stack_get_top(bin_node_stack* stack);

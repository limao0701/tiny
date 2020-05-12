#include "stack.h"

void push_to_bin_node_stack(bin_node_stack *stack,int data);
bin_node_stack * bin_node_stack_sort(bin_node_stack *stack, int n);
bin_node * get_small(bin_node_stack *stack, bin_node_queue *queue);
void bin_node_trav_pre_value(bin_node *root,
                             void(*trave_fun)(bin_node *node,void* store_value,int steps),
                             void* store_value,int steps);
void trave_fun(bin_node *node,void* store_value,int steps);                            
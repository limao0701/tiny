#include "stack.h"

typedef struct bin_node_list_node{
    bin_node * node;
    struct bin_node_list_node *next;
    struct bin_node_list_node *pre;
}bin_node_list_node;


void push_to_bin_node_stack(bin_node_stack *stack,long data);
bin_node_stack * bin_node_stack_sort(bin_node_stack *stack, int n);
bin_node * get_small(bin_node_stack *stack, bin_node_queue *queue);
void bin_node_trav_pre_value(bin_node *root,
                             void(*trave_fun)(bin_node *node,void* store_value,long steps),
                             void* store_value,long steps);
void trave_fun(bin_node *node,void* store_value,long steps);     

void bin_node_insert_inorder(bin_node_list_node *head,bin_node_list_node *node);
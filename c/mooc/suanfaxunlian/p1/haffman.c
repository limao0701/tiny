#include<stdio.h>
#include<stdlib.h>
#include"haffman.h"

int main(){
    int n=0;
    int data;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    bin_node_stack *stack=bin_node_stack_new(n);
    bin_node_queue *bin_queue=bin_node_queue_new(n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        push_to_bin_node_stack(stack,data);
    }
    bin_node_stack *sorted_stack=bin_node_stack_sort(stack,n);
    free(stack);
    bin_node *node_root_ptr=NULL;

    while(!sorted_stack->isempty(sorted_stack) || !bin_queue->isempty(bin_queue)){
        
        bin_node *a=get_small(sorted_stack, bin_queue);
        bin_node *b=get_small(sorted_stack, bin_queue);
        if(!a || !b){
            break;
        }

        node_root_ptr=bin_node_new(a->data + b->data);
        node_root_ptr->l_child=a;
        node_root_ptr->r_child=b;
        node_root_ptr->update_height(node_root_ptr);
        bin_queue->enqueue(bin_queue,node_root_ptr);

    }
    int total_str_len=0;
    bin_node_trav_pre_value(node_root_ptr,trave_fun,(void *)&total_str_len,0);
    printf("%d",total_str_len);
    return 0;

}



void push_to_bin_node_stack(bin_node_stack *stack,int data){
    bin_node *bin_node_ptr=bin_node_new(data);
    stack->push(stack,bin_node_ptr);
    return;
}

bin_node_stack * bin_node_stack_sort(bin_node_stack *stack, int n){

	bin_node_stack *sorted_stack=bin_node_stack_new(n);
        bin_node  *b=NULL;
        bin_node  *c=NULL;
	while(!sorted_stack->isfull(sorted_stack)){
        if(sorted_stack->isempty(sorted_stack)){
        		sorted_stack->push(sorted_stack,stack->pop(stack));
		}
		b=sorted_stack->pop(sorted_stack);
		c=stack->pop(stack);
		if(b->data >= c->data){
			sorted_stack->push(sorted_stack,b);
			sorted_stack->push(sorted_stack,c);	
		}
		else{
			stack->push(stack,b);
			stack->push(stack,c);
		}
	}
    return sorted_stack;

}

bin_node * get_small(bin_node_stack *stack, bin_node_queue *queue){
    if(stack->isempty(stack) && queue->isempty(queue)){
        return NULL;
    }
    if(stack->isempty(stack)){
        return queue->dequeue(queue);
    }
    if(queue->isempty(queue)){
        return stack->pop(stack);
    }
    if((stack->get_top(stack))->data < (queue->get_tail(queue))->data){
        return stack->pop(stack);
    }
    else{
        return queue->dequeue(queue);
    }
}


void bin_node_trav_pre_value(bin_node *root,
                             void(*trave_fun)(bin_node *node,void* store_value,int steps),
                             void* store_value,int steps){
    if(!root){  
        
        return;
    }
    if(root->l_child){
        bin_node_trav_pre_value(root->l_child,trave_fun,store_value,steps+1);
    }
    if(root->r_child){
        bin_node_trav_pre_value(root->r_child,trave_fun,store_value,steps+1);
    }
    if( (!root->r_child) && (!root->r_child) ){
        trave_fun(root,store_value,steps);
        return;
    }
}

void trave_fun(bin_node *node,void* store_value,int steps){
    *((int*)store_value)+= steps * node->data;
    return;
}

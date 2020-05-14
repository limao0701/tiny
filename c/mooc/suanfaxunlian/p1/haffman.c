#include<stdio.h>
#include<stdlib.h>
#include"haffman.h"
#include<time.h>

int main(){
    int n=0;
    srand(time(NULL));
    long data;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    bin_node_stack *stack=bin_node_stack_new(n);
    bin_node_stack *stack_for_list=bin_node_stack_new(n);
    bin_node_queue *bin_queue=bin_node_queue_new(n);
    for(int i=0;i<n;i++){
        scanf("%ld",&data);
        /*data=(rand()*200)+1;
        if(data<0){
            data=-data;
        }
        printf("%ld\n",data);
        */
        push_to_bin_node_stack(stack,data);
 //       push_to_bin_node_stack(stack_for_list,data);
        
    }
    bin_node_stack *sorted_stack=bin_node_stack_sort(stack,n);
/*
    bin_node_list_node *head=(bin_node_list_node*)malloc(sizeof(bin_node_list_node));
    bin_node_list_node *list_node=NULL;
    head->next=NULL;
    head->pre=head;
    while(!stack_for_list->isempty(stack_for_list)){
        list_node=(bin_node_list_node*)malloc(sizeof(bin_node_list_node));
        list_node->node=stack_for_list->pop(stack_for_list);
        bin_node_insert_inorder(head,list_node);

    }
    head=head->next;
    bin_node_list_node *a;
    bin_node_list_node *b;
    bin_node_list_node *tmp_bin_node_list_node;
    bin_node * temp_root_node;
    while(head){
        if(!head->next){
            break;
        }
        a=head;
        head=head->next;
        b=head;
        
        tmp_bin_node_list_node=(bin_node_list_node *)malloc(sizeof(bin_node_list_node));
        temp_root_node=malloc(sizeof(bin_node));
        temp_root_node->data=(a->node->data + b->node->data );
        temp_root_node->l_child=a->node;
        temp_root_node->r_child=b->node;
        tmp_bin_node_list_node->node=temp_root_node;
        bin_node_insert_inorder(head,tmp_bin_node_list_node);
        head=head->next;
    }


*/

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
    long total_str_len=0;
    bin_node_trav_pre_value(node_root_ptr,trave_fun,(void *)&total_str_len,0);
    printf("%ld\n",total_str_len);

    //total_str_len=0;
    //bin_node_trav_pre_value(head->node,trave_fun,(void *)&total_str_len,0);
    //printf("%ld",total_str_len);
    return 0;

}



void push_to_bin_node_stack(bin_node_stack *stack,long data){
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
                             void(*trave_fun)(bin_node *node,void* store_value,long steps),
                             void* store_value,long steps){
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

void trave_fun(bin_node *node,void* store_value,long steps){
   // printf("Data is:%ld\n",node->data);
    *((long*)store_value)+= (long)steps * node->data;
    return;
}

void bin_node_insert_inorder(bin_node_list_node *head,bin_node_list_node *node){
    while(head->next){
        head=head->next;
        if(node->node->data <= head->node->data){  
            node->next=head;
            node->pre=head->pre;
            head->pre->next=node;
            head->pre=node;
            return;
        }

    }
    //if no next for current head 
    head->next=node;
    node->next=NULL;
    node->pre=head;
}




#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int array_stack_isempty(array_stack * stack){
	if(stack->botom==stack->top){
		return 1;
	}
	else{
		return 0;
	}
}


int array_stack_push(array_stack *stack,char* value){
	if(stack->size <= stack->top - stack->botom){
		return -1;
	}
	*((stack->top)++)=value;
	return 0;
}

char *array_stack_pop(array_stack *stack){
	if((stack->top) - stack->botom <=0){
		return NULL;
	}
	return *(--stack->top);
}


array_stack *array_stack_new(int size){
	array_stack*stack=(array_stack *)malloc(sizeof(array_stack));
	char**array=(char**)malloc(sizeof(char*)*(size_t)size);
	stack->self=stack;
	stack->size=size;
	stack->botom=array;
	stack->top=array;
	stack->push=array_stack_push;
	stack->pop=array_stack_pop;
	stack->isempty=array_stack_isempty;
	stack->get_top=stack_top;
	return stack;
}


char *stack_top(struct array_stack*stack){
    if(stack->isempty(stack)){
		return NULL;
	}
	return *((stack->top)-1);
}

int array_stack_destroy(array_stack* stack){
	free(stack->botom);
	free(stack);
	return 0;
}

//bin_node stack methods

int bin_node_stack_isempty(bin_node_stack * stack){
	if(stack->botom==stack->top){
		return 1;
	}
	else{
		return 0;
	}
}

int bin_node_stack_isfull(struct bin_node_stack*stack){
	return (stack->top - stack->botom == stack->size);
}

int bin_node_stack_push(bin_node_stack *stack,bin_node *value){
	if(stack->size <= stack->top - stack->botom){
		return -1;
	}
	*((stack->top)++)=value;
	return 0;
}

bin_node *bin_node_stack_pop(bin_node_stack *stack){
	if((stack->top) - stack->botom <=0){
		return NULL;
	}
	return *(--stack->top);
}


bin_node_stack *bin_node_stack_new(int size){
	bin_node_stack *stack=(bin_node_stack *)malloc(sizeof(bin_node_stack));
	bin_node **array=(bin_node **)malloc(sizeof(bin_node *)*(size_t)size);
	stack->self=stack;
	stack->size=size;
	stack->botom=array;
	stack->top=array;
	stack->push=bin_node_stack_push;
	stack->pop=bin_node_stack_pop;
	stack->isempty=bin_node_stack_isempty;
	stack->isfull=bin_node_stack_isfull;
	stack->get_top=bin_node_stack_get_top;
	return stack;
}


bin_node *bin_node_stack_get_top(bin_node_stack*stack){
    if(stack->isempty(stack)){
		return NULL;
	}
	return *((stack->top)-1);
}

int bin_node_stack_destroy(bin_node_stack* stack){
	free(stack->botom);
	free(stack);
	return 0;
}



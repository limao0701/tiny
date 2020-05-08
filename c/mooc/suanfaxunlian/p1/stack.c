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
	stack->stack_push=array_stack_push;
	stack->stack_pop=array_stack_pop;
	stack->stack_isempty=array_stack_isempty;
	stack->stack_top=stack_top;
	return stack;
}


char *stack_top(struct array_stack*stack){
    if(stack->stack_isempty(stack)){
		return NULL;
	}
	return *((stack->top)-1);
}

int array_stack_destroy(array_stack* stack){
	free(stack->botom);
	free(stack);
	return 0;
}






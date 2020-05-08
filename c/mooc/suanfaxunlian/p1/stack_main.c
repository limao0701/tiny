#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"stack.h"


#define POP 2
#define PUSH 1
#define POSITION 3
int main(){
    int n=0;
    scanf("%d",&n);
    array_stack *stack=array_stack_new(n);
    array_stack *stack_print=array_stack_new(n);
    int op=0;
    char data[16];
    int  pos;
    char *tmp;

    for(int i=0;i<n;i++){
        //printf("%d\n",i);
        scanf("%d",&op);
        if(op==PUSH){
            scanf("%s",data);
            char*stor_data=(char*)malloc((size_t)(strlen(data)+1));
            strcpy(stor_data,data);
            stack->stack_push(stack,stor_data);
            continue;
        }
        if(op==POP && !stack->stack_isempty(stack)){
            stack_print->stack_push(stack_print,stack->stack_pop(stack));
            continue;
        }
        if(op==POSITION && !stack->stack_isempty(stack)){
           scanf("%d",&pos);
           stack_print->stack_push(stack_print,*(stack->botom+pos-1)); 
           continue;
        }
    }
    array_stack *stack_print_reverse=array_stack_new(n);
    while(!stack_print->stack_isempty(stack_print)){
        stack_print_reverse->stack_push(stack_print_reverse,stack_print->stack_pop(stack_print));
    }
    while(!stack_print_reverse->stack_isempty(stack_print_reverse)){
        tmp=stack_print_reverse->stack_pop(stack_print_reverse);
        printf("%s\n",tmp);
    }

    array_stack_destroy(stack);
    array_stack_destroy(stack_print);
    array_stack_destroy(stack_print_reverse);

}



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stack.h"
void stack_sort(unsigned int a[],unsigned int n);
void stack_push_pop_sort(unsigned int a[],unsigned int n);

int main(){
/*
        srand(time(NULL));
        unsigned int max_len=1;
	scanf("%u",&max_len);
        unsigned int n=max_len;
        unsigned int a[n];
        for(unsigned int i=0;i<n;i++){
		a[i]=(unsigned int)rand()%32767;
	}
*/
	unsigned int n=0;
	scanf("%u",&n);
	unsigned a[n];
	for(unsigned int i=0;i<n;i++){
		scanf("%u",&a[i]);	
	}

//	stack_sort(a,n);
	stack_push_pop_sort(a,n);
	return 0;	

}

void stack_sort(unsigned int a[],unsigned int n){
	unsigned int i=0;
	unsigned int temp;
	while(i<n-1){
		temp=a[i+1];
		if(a[i]<=temp){
			i++;
		}	
		else{
			a[i+1]=a[i];
			a[i]=temp;
			if(i>=1){
				i--;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%u\n",a[i]);
	}
	
}
void stack_push_pop_sort(unsigned int a[],unsigned int n){
	array_stack*stack=array_stack_new(n);
	for(unsigned int i=0;i<n;i++){
        	stack->stack_push(stack,a[i]);
	}
	array_stack*sorted_stack=array_stack_new(n);
        unsigned int b,c;
	while(sorted_stack->top - sorted_stack->botom != n){
                if(sorted_stack->stack_isempty(sorted_stack)){
        		sorted_stack->stack_push(sorted_stack,stack->stack_pop(stack));
		}
		b=sorted_stack->stack_pop(sorted_stack);
		c=stack->stack_pop(stack);
		if(b>=c){
			sorted_stack->stack_push(sorted_stack,b);
			sorted_stack->stack_push(sorted_stack,c);	
		}
		else{
			stack->stack_push(stack,b);
			stack->stack_push(stack,c);
		}
	}
        while(!sorted_stack->stack_isempty(sorted_stack)){
		printf("%u\n",sorted_stack->stack_pop(sorted_stack));
	}
        array_stack_destroy(stack);
        array_stack_destroy(sorted_stack);
        return;

}

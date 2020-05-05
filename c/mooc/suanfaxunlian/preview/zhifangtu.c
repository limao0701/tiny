#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include"stack.h"


unsigned int find_small_index(unsigned int a[],unsigned int n);
unsigned int force(unsigned int a[],unsigned int n);
unsigned int recursion(unsigned int a[],int n);
unsigned int by_stack(unsigned int a[],int n);
int main(){
/*        
	srand(time(NULL));
	unsigned int max_len=1;
	scanf("%u",&max_len);
    unsigned int n=max_len;
    unsigned int a[n];
    for(unsigned int i=0;i<n;i++){
		a[i]=(unsigned int)rand()%32767;
		//printf("%u\n",a[i]);
	}
*/
///*
	unsigned int n;
	scanf("%u",&n);
	unsigned int a[n];
	for(unsigned int i=0;i<n;i++){
    	scanf("%u",&a[i]);
	}
 //*/
//	printf("%u",force(a,n));
//	printf("\n");
//	printf("%u",recursion(a,(int)n));
//	printf("\n");
	printf("%u",by_stack(a,(int)n));
	return 0;
}


unsigned int recursion(unsigned int a[],int n){
	if(n==1){
		return a[0];
	}
	if(n<=0){
		return (unsigned int )0;
	}
	unsigned int small=find_small_index(a,n);
	unsigned int squal=a[small]*(unsigned int)n;
	unsigned int left_squal=recursion(a,(int)small);
	unsigned int right_squal=recursion(a+small+1,n-small-1);
	squal=(squal < left_squal)? left_squal:squal;
	squal=(squal < right_squal)? right_squal:squal;
	return squal;
	
}
unsigned int force(unsigned int a[],unsigned int n){
        unsigned int large=0;
	unsigned int small=0;
	unsigned int squal=0;
	for(unsigned int i=0;i<n;i++){
		for(unsigned int j=i;j<n;j++){
			small=find_small_index(&a[i],j-i+1);
			squal=a[i+small]*(j-i+1);
                        if(large<squal){
				large=squal;
			}

		}
	}
	return large;

}

unsigned int find_small_index(unsigned int a[],unsigned int n){
	unsigned int index=0;
	unsigned int small=a[0];
	for(unsigned int i=1;i<n;i++){
		if(a[i]<small){
                        small=a[i];
			index=i;
		}
	}
	return index;
}



unsigned int by_stack(unsigned int a[],int n){
	array_stack*rank_stack=array_stack_new(n);
	int top_k=0;
	unsigned int max_area=0;
	unsigned int temp_max=0;
	int pre_stack_top=0;
	for(int k=0;k<n;){
		if( rank_stack->stack_isempty(rank_stack) || a[rank_stack->stack_top(rank_stack)] <= a[k] ){
			rank_stack->stack_push(rank_stack,k);
			k++;
			
		}
		else{
			top_k=rank_stack->stack_pop(rank_stack);
			if( rank_stack->stack_isempty(rank_stack)){
				pre_stack_top=-1;
			}
			else{
				pre_stack_top=rank_stack->stack_top(rank_stack);
			}
			temp_max=(unsigned int)(k-pre_stack_top-1) * a[top_k];
			max_area=(temp_max < max_area)?max_area:temp_max;
		}
	}
	while(!rank_stack->stack_isempty(rank_stack)){
		top_k=rank_stack->stack_pop(rank_stack);
		if( rank_stack->stack_isempty(rank_stack)){
			pre_stack_top=-1;
		}
		else{
			pre_stack_top=rank_stack->stack_top(rank_stack);
		}
		temp_max=(unsigned int)(n - pre_stack_top - 1) * a[top_k];
		max_area=(temp_max < max_area)?max_area:temp_max;
	}
	return max_area;
}


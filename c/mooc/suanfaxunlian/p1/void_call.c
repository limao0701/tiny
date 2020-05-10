#include<stdio.h>
#include<stdlib.h>
void callme(){
	printf("in callme\n");
	return ;
}

int main(){
	void (*void_call)(void)=NULL;
	void_call();
	void_call=callme;
	void_call();
	return 0;
}

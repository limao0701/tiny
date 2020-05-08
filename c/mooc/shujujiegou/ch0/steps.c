#include<stdio.h>


int steps(int n){
	if(n<=1){
		return 1;
	}
	return steps(n-1)+steps(n-2);
}

int main(){
	printf("%d",steps(7));
}

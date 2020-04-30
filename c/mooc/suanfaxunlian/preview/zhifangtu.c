#include<stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int find_small_index(unsigned int a[],unsigned int n);
unsigned int force(unsigned int a[],unsigned int n);
unsigned int recursion(unsigned int a[],int n);

int main(){
        srand(time(NULL));
        unsigned int max_len=1;
	scanf("%u",&max_len);
        unsigned int n=max_len;
        unsigned int a[n];
        for(unsigned int i=0;i<n;i++){
		srand(time(NULL));
		a[i]=(unsigned int)rand()%32767;
	}
/*	unsigned int n;
	scanf("%u",&n);
	unsigned int a[n];
	for(unsigned int i=0;i<n;i++){
    		scanf("%u",&a[i]);
	}
*/
	printf("%u",force(a,n));
        printf("\r\n%u",recursion(a,(int)n));
	return 0;
}


unsigned int recursion(unsigned int a[],int n){
	if(n==1){
		return a[0];
	}
	if(n<=0){
		return 0;
	}
	unsigned int small=find_small_index(&a[0],n);
	unsigned int squal=a[small]*(unsigned int )n;
	unsigned int left_squal=recursion(&a[0],(int)small-1);
	unsigned int right_squal=recursion(&a[small+1],n-(int)small-1);
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

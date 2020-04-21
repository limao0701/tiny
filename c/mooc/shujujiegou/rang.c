#include <stdio.h>
#define DEBUG
int main(void){
    unsigned n;
    unsigned m;
    scanf("%u %u",&n,&m);
    unsigned int data[n];
    unsigned int i=0;
    while(i<n){
        scanf("%u",&data[i]);
	i++;
    }

    i=0;
    unsigned int range[m][2];
    while(i < m){
	    scanf("%u %u",&range[i][0],&range[i][1]);
	    i++;
    }

#ifdef DEBUG
#endif
    return 0;
}



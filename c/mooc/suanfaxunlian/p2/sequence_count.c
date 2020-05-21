#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void print_seq(long *array,int low,int high);
void update_max_index(long *array,int * low,int *high,int *max,int*min,long d);
void update_min_index(long *array,int * low,int *high,int *max,int*min,long d);

int main(){

/*
    srand(time(NULL));
    
    int n=0;
    long d=0;
    scanf("%d",&n);
    scanf("%ld",&d);
    long * array=(long *)malloc(sizeof(long) * n);
    for(int i=0;i<n;i++){
        array[i]=rand();
        printf("%ld ",array[i]);
    }
  */  
 ///*   
    int n=0;
    long d=0;
    scanf("%d",&n);
    scanf("%ld",&d);
    if(!n){
        return 0;
    }
    long * array=(long *)malloc(sizeof(long) * n);
    for(int i=0;i<n;i++){
        scanf("%ld",&array[i]);
    }
//*/
    int low=0;
    int high=0;
    int max=0;
    int min=0;
    long long total=0;
    for(int i=0;i<n;i++){
        high=i;
        if(array[i]>array[max]){
            max=i;
            update_min_index(array,&low,&high,&max,&min,d);
        }
        else if(array[i]<array[min]){
            min=i;
            update_max_index(array,&low,&high,&max,&min,d);
        }
        total+=(high-low);
        //print_seq(array,low,high);
    }
    printf("%lld",total);
    return 0;
}



void print_seq(long *array,int low,int high){
//    printf("High: %d, low: %d\n",high,low);
    if(high-low<1){
        return;
    }
    for(int i=low;i<high;i++){
        for(int j=i;j<=high;j++){
            printf("%ld ",array[j]);  
        }   
        printf("\n");
    }
}


void update_max_index(long *array,int * low,int *high,int *max,int*min,long d){
//    printf("Update max: Max: %d, min: %d,High: %d, low: %d\n",*max,*min,*high,*low);
    int length=*high-*low;
    for(int max_index=*max+1;max_index<=*high;max_index++ ){
        if(array[max_index]>array[*max]){
            *max=max_index;
        } 
        if(array[*max]-array[*min]>d){
            max_index=*max;
            *low=++*max;
        }
    }

}
void update_min_index(long *array,int * low,int *high,int *max,int*min,long d){
//    printf("Update min: Max: %d, min: %d,High: %d, low: %d\n",*max,*min,*high,*low);
    int length=*high-*low;
    for(int min_index=*min+1;min_index<=*high;min_index++ ){
        if(array[min_index]<array[*min]){
            *min=min_index;
        } 
        if(array[*max]-array[*min]>d){
            min_index=*min;
            *low=++*min;
        }
    }
    
//    printf("updated\n");
}
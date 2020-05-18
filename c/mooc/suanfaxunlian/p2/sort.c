#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long *my_mergesort(long *a,int n);

int main(){
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    long *a=(long *)malloc(sizeof(long) * n);
    for(int i=0;i<n;i++){
        scanf("%ld",a+i);
    }
    a=my_mergesort(a,n);
    for(int i=0;i<n;i++){
        printf("%ld ",a[i]);
    }
    return 0;
}

//merge sort 无法原地排序？？？代码稍微复杂。
long *my_mergesort(long *a,int n){
    //printf("%d\n",n);
    if(n<=1){
        return a;
    }
    int mid=n>>1;
    long*left_a=my_mergesort(a,mid);
    long*right_a=my_mergesort(a+mid,n-mid);
    long *new_a=(long *)malloc(sizeof(long)*n);
    int i=0;
    int j=0;
    int k=0;
    for( ; k<n && i<mid && j<n-mid ; k++){
        if(left_a[i]<=right_a[j]){
            new_a[k]=left_a[i++];
        }

        else{
            new_a[k]=right_a[j++];
        }
        
    }
    long *not_in_new_a=left_a;
    int not_in_new_a_index=i;
    if(i==mid){
        not_in_new_a=right_a;
        not_in_new_a_index=j;
    }
    for( ; k<n ; k++){
        new_a[k]=not_in_new_a[not_in_new_a_index++];
    }
    //free(a);
    return new_a;
}
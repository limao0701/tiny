#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max_sum(int *a,int n,int i,int j);
int max_sum_dynamic(int *a,int n,int i,int j,int *max_a);
int my_max(int a, int b);



int main(){
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    int * a=(int *)malloc(sizeof(int)*n*n);
    int * sum_a=(int *)malloc(sizeof(int)*n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",a+i*n+j);
            *(sum_a+i*n+j)=0;
        }
    }
    int out_max=max_sum(a,n,n-1,0);
    /*
    for(int i=1;i<n;i++){
        out_max=my_max(out_max,max_sum(a,n,n-1,n-1));
    }
   
    printf("%d",out_max);
    for(int j=1;j<n;j++){
        out_max=my_max(out_max,max_sum(a,n,n-1,j));
    }*/
    out_max=*sum_a;
    for(int j=0;j<n;j++){
        out_max=my_max( out_max , max_sum_dynamic(a,n,n-1,j,sum_a) );
    }
    printf("%d",out_max);
    return 0;
}

int max_sum(int *a,int n,int i,int j){
//    printf("n=[%d],a[%d][%d]=%d\n",n,i,j,*(a+i*n+j));
    if(i==0){
        return *(a+j);
    }
    if(j==0){
        return *(a+i*n+j) + max_sum(a,n,i-1,j);
    }
    if(j==i){
        return *(a+i*n+j) + max_sum(a,n,i-1,j-1);
    }
    return *(a+i*n+j) + my_max(max_sum(a,n,i-1,j-1),max_sum(a,n,i-1,j));
}

int my_max(int a, int b){
    return a>b?a:b;
}


int max_sum_dynamic(int *a,int n,int i,int j,int *max_a){
    //printf("max a[%d][%d]\n",i,j);
    if(i==0){
        *(max_a+j)=*(a+j);
        return *(max_a+j);
    }
    int above_sum= *(max_a+(i-1)*n+j);
    int above_left_sum= *(max_a+(i-1)*n+j-1);
    if(j==0){
        if(above_sum){
            *(max_a+i*n+j) =  *(a+i*n+j) +  above_sum;
            return *(max_a+i*n+j);
        }
        else{
            *(max_a+i*n+j)= *(a+i*n+j) + max_sum_dynamic(a,n,i-1,j,max_a);
            return *(max_a+i*n+j);
        }
        
    }
    if(j==i){
        if(above_left_sum){
            *(max_a+i*n+j)=*(a+i*n+j) + above_left_sum;;
            return *(max_a+i*n+j);
        }
        else{
            *(max_a+i*n+j)=*(a+i*n+j) + max_sum_dynamic(a,n,i-1,j-1,max_a);
            return *(max_a+i*n+j)=*(a+i*n+j);
        }
    }
    if(!above_left_sum){
        above_left_sum = max_sum_dynamic(a,n,i-1,j-1,max_a);
    }
    if(!above_sum){
        above_sum = max_sum_dynamic(a,n,i-1,j,max_a);
    }
    *(max_a+i*n+j) =   *(a+i*n+j)+my_max(above_left_sum,above_sum);
    return  *(max_a+i*n+j);
    
}
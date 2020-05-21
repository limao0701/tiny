#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void array_clean(int i,int j);

int main(){
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    int * array=(int *)malloc(sizeof(int)*n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i*n+j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            array_clean(i,j);
        }
    }
    int max=0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max+=a[i*n+j];
        }
    }
}


void array_clean(int *array,int i,int j,int n){
    if(array[i*n+j]==1){

    }
}



int cost_if_keep(int *array ,int i,int j,int n){
    int row_sum=0;
    for(int k=0;k<n;k++){
        row_sum+=array[i*n+k];
    }
    int colum_sum=0;
    for(int k=0;k<n;k++){
        colum_sum+=array[k*n+j];
    }
    return row_sum+colum_sum-2;
    }
}
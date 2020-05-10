#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

int force_find_op(hash_data *data_head,long x,int op);

int main(){
    /*        
	srand(time(NULL));
	unsigned int max_len=1;
	scanf("%u",&max_len);
    unsigned int n=max_len;
    unsigned int a[n];
    char *out=malloc(sizeof(char)*n);
    char *out2=malloc(sizeof(char)*n);
    hash_table * my_hash_table=hash_table_new(n,90001);
    hash_data *data_head=(hash_data *)malloc(sizeof(hash_data));
    data_head->pre=data_head;
    data_head->sur=NULL;
    for(unsigned int i=0;i<n;i++){
        long rand_long=rand()%1000;
        rand_long*=10000000000000;
        printf("%ld\n",rand_long);
        int op_rand=(int)rand()&1+1;
        if(force_find_op(data_head,rand_long,op_rand)){
            out2[i]=1;
        }
        else{
            out2[i]=0;
        }
        if(op_rand==1){          
            out[i]=hash_table_insert(my_hash_table,rand_long);
        }
        else{
            out[i]=hash_table_remove(my_hash_table,rand_long);
        }
        printf("%d\n",i);
    }
   */


///*
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    int op=0;
    long data=0;
    char *out=malloc(sizeof(char)*n);
    char *out2=malloc(sizeof(char)*n);
    hash_table * my_hash_table=hash_table_new(n,90001);
    hash_data *data_head=(hash_data *)malloc(sizeof(hash_data));
    data_head->pre=data_head;
    data_head->sur=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&op);
        scanf("%ld",&data);
        if(force_find_op(data_head,data,op)){
            out2[i]=1;
        }
        else{
            out2[i]=0;
        }
        /*
        if(op==1){           
            out[i]=hash_table_insert(my_hash_table,data);
        }
        else{
            out[i]=hash_table_remove(my_hash_table,data);
        }
        */
    }
//*/

    for(int i=0;i<n;i++){
        if(out2[i]==0){
            printf("Failed\n");
        }
        else{
            printf("Succeeded\n");
        }

    }    
    return 0;


}


int force_find_op(hash_data *data_head,long x,int op){
    hash_data *tmp=data_head->sur;
    while(tmp){
        if(tmp->data == x){
            if(op==1){   //insert exist number;
                return 0;
            }
            if(op==2){   //remove exist number;
                tmp->pre->sur=tmp->sur;
                if(tmp->sur){
                    tmp->sur->pre=tmp->pre;
                }
                free(tmp);
                return 1;
            }
        }
        tmp=tmp->sur;
    }
    if(op==1){
        tmp=(hash_data *)malloc(sizeof(hash_data));
        tmp->data=x;
        tmp->sur=data_head->sur;
        tmp->pre=data_head;
        data_head->sur=tmp;
        return 1;
    }
    else{
        return 0;
    }

}
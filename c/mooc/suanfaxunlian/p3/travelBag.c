#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct object{
    int is_mult;
    int value;
    int volume;
}object_t;

int max_value(object_t *a,int n,int index, int max_volume);
int max_value_dynamic(object_t *a,int n,int index, object_t *max_in_mem);
int my_max(int a, int b);




int main(){
    int n=0;
    int allowed_volume=0;
    scanf("%d",&n);
    scanf("%d",&allowed_volume);
    if(!n){
        return 0;
    }
    int input_obj_mult=0;
    int input_obj_value=0;
    int input_obj_volume=0;
    object_t * obj_head=(object_t *)malloc(sizeof(object_t)*n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&input_obj_mult,&input_obj_value,&input_obj_volume);
        obj_head[i].is_mult=input_obj_mult;
        obj_head[i].value=input_obj_value;
        obj_head[i].volume=input_obj_volume;
    }
   /* for(int i=0;i<n;i++){
        printf("%d %d %d\n",obj_head[i].is_mult,obj_head[i].value,obj_head[i].volume);
    }*/
    printf("%d",max_value(obj_head,  n, n-1, allowed_volume));
    return 0;

}



int my_max(int a, int b){
    return a>b?a:b;
}


int max_value(object_t *a,int n,int index, int max_volume){
  //  printf("index=%d,max_volume=%d\n",index,max_volume);
    int max=0;
    int max_obj_num=my_max(1,max_volume*a[index].is_mult/a[index].volume);
    if(max_volume==0){
        return 0;
    }
    if(index==0){
        max= max_volume/a[index].volume * a[index].value*a[index].is_mult 
             + (!(a[index].is_mult))*(max_volume>a[index].volume)*a[index].value ;
     //   printf("Return max=%d\n",max);
        return max;
    }
 //   printf("Inner index=%d,max_volume=%d\n",index,max_volume);
    max = my_max(max,  max_value(a, n, index-1, max_volume)); //not put any of a[index] to bag
    if(max_volume<a[index].volume){
        return max;
    }

    //max = my_max(max,  a[index].value * max_obj_num + max_value(a, n, index-1, max_volume - a[index].volume * max_obj_num));
    for(int i=1 ; i <= max_obj_num ;i++){
        //if  put i x a[index].volume objs to bag,
        max = my_max(max,  a[index].value * i + max_value(a, n, index-1, max_volume - a[index].volume * i));
    }
  //  printf("Return max=%d\n",max);
    return max;

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct score{
    int total;
    int dst_pra;
    int dst;
    int number;
}score_t;
typedef score_t * score_ptr;
int bubble_sort(score_t *array[],int n);

int main(){
    int n=0;
    srand(time(NULL));
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    int dst=0;
    int dst_pra=0;
    score_t *scores_array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&dst_pra);
        scanf("%d",&dst);
        scores_array[i]=(score_t *)malloc(sizeof(score_t));
        scores_array[i]->number=i+1;
        scores_array[i]->dst=dst;
        scores_array[i]->dst_pra=dst_pra;
        scores_array[i]->total=dst+dst_pra;
    }
    //printf("Sorting\n");
    int reversed=bubble_sort(scores_array,n);
    for(int i=0;i<n;i++){
        printf("%d %d %d %d\n",scores_array[i]->number,scores_array[i]->total,scores_array[i]->dst_pra,scores_array[i]->dst);
    }
    printf("%d",reversed);

    return 0;
}


int bubble_sort(score_t *a[],int n){
    int sorted=1;
    int reversed=0;
    int right_sorted=n-1;
    score_t *tmp;
    n--;
    do{
        //n--;
        //printf("n=%d\n",n);
        sorted=1;
        for(int i=0;i<n;i++){
            if(a[i]->total <= a[i+1]->total){
                if(a[i]->total == a[i+1]->total && a[i+1]->dst_pra < a[i]->dst_pra){
                       continue;
                }
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                sorted=0;
                if(a[i+1]->number < a[i]->number ){
                    reversed++;
                }
                right_sorted=i;
                continue;
            }

        }
        n=right_sorted;
    }while(!sorted);
    return reversed;
    
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

#define ENQUEUE 1
#define DEQUEUE 2
#define POSITION 3

int main(){
    int n=0;
    scanf("%d",&n);
    array_queue *queue=array_queue_new(n);
    array_queue *queue_print=array_queue_new(n);
    int op=0;
    char data[16];
    int  pos;
    char *tmp;

    for(int i=0;i<n;i++){
        //printf("%d\n",i);
        scanf("%d",&op);
        if(op==ENQUEUE){
            scanf("%s",data);
            char*stor_data=(char*)malloc((size_t)(strlen(data)+1));
            strcpy(stor_data,data);
            queue->enqueue(queue,stor_data);
            continue;
        }
        if(op==DEQUEUE && !queue->isempty(queue)){
            queue_print->enqueue(queue_print,queue->dequeue(queue));
            continue;
        }
        if(op==POSITION && !queue->isempty(queue)){
           scanf("%d",&pos);
           queue_print->enqueue(queue_print,queue->get_position(queue,pos-1)); 
           continue;
        }
    }

    while(!queue_print->isempty(queue_print)){
        printf("%s\n",queue_print->dequeue(queue_print));
    }


    array_queue_destroy(queue);
    array_queue_destroy(queue_print);

}

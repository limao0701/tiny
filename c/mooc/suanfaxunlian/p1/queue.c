#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int array_queue_isempty(array_queue * queue){
    return(!queue->current_size);
}

int array_queue_isfull(array_queue * queue){
    return(queue->current_size==queue->size);
}

int array_queue_enqueue(array_queue *queue,char* value){
    if(!queue->isfull(queue)){
        *queue->head=value;
        queue->current_size++;
        if((queue->head++) == queue->array_end){
            queue->head = queue->array;
        }
        return TRUE;
    }
    return FALSE;
}
char *array_queue_dequeue(array_queue *queue){
    if(queue->isempty(queue)){
        return NULL;
    }
    char * value= *queue->tail;
    queue->tail++;
    if(queue->tail==queue->array_end){
        queue->tail=queue->array;
    }
    queue->current_size--;
    return value;
}

char *array_queue_get_tail(struct array_queue *queue){
    if(queue->isempty(queue)){
        return NULL;
    }
    return *queue->tail;
}
char *array_queue_get_head(struct array_queue *queue){
    if(queue->isempty(queue)){
        return NULL;
    }
    return *queue->head;

}


char *array_queue_get_position(struct array_queue *queue,int n){
    if(queue->current_size <= n){
        return NULL;
    }
    char ** tmp=queue->tail + n;
    if(tmp>=queue->array_end){
        tmp=queue->array + (queue->tail + n - (queue->array_end-1));
    }
    return *tmp;
}

array_queue *array_queue_new(int size){
    array_queue*queue=(array_queue *)malloc(sizeof(array_queue));
    queue->current_size=0;
	queue->array=(char**)malloc(sizeof(char*)*(size_t)size);
    queue->array_end=queue->array+size;
	queue->self=queue;
	queue->size=size;
	queue->tail=queue->array;
	queue->head=queue->array;
	queue->enqueue=array_queue_enqueue;
	queue->dequeue=array_queue_dequeue;
	queue->isempty=array_queue_isempty;
	queue->isfull=array_queue_isfull;
    queue->get_head=array_queue_get_head;
    queue->get_tail=array_queue_get_tail;
    queue->get_position=array_queue_get_position;
	return queue;
}
int array_queue_destroy(array_queue* queue){
    free(queue->array);
	free(queue);
	return 0;
}
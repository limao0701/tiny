#include "bin_tree.h"
#define TRUE 1
#define FALSE 0

typedef struct array_queue{
        struct array_queue * self;
        int size;
        int current_size;
        char **array;
        char **array_end;
        char **head;
        char **tail;
        int (*enqueue)(struct array_queue *queue,char *value);
        char *(*dequeue)(struct array_queue *queue);
        int (*isempty)(struct array_queue *queue);
        int (*isfull)(struct array_queue *queue);
        char *(*get_head)(struct array_queue *queue);
        char *(*get_tail)(struct array_queue *queue);
        char *(*get_position)(struct array_queue *queue,int n);
}array_queue;

int array_queue_isempty(array_queue * queue);
int array_queue_isfull(array_queue * queue);
int array_queue_enqueue(array_queue *queue,char* value);
char *array_queue_dequeue(array_queue *queue);
char *array_queue_get_tail(struct array_queue *queue);
char *array_queue_get_head(struct array_queue *queue);
char *array_queue_get_position(struct array_queue *queue,int n);
array_queue *array_queue_new(int size);
int array_queue_destroy(array_queue* queue);


//bin node queue:

typedef struct bin_node_queue{
        struct bin_node_queue * self;
        int size;
        int current_size;
        bin_node **array;
        bin_node **array_end;
        bin_node **head;
        bin_node **tail;
        int (*enqueue)(struct bin_node_queue *queue,bin_node *value);
        bin_node *(*dequeue)(struct bin_node_queue *queue);
        int (*isempty)(struct bin_node_queue *queue);
        int (*isfull)(struct bin_node_queue *queue);
        bin_node *(*get_head)(struct bin_node_queue *queue);
        bin_node *(*get_tail)(struct bin_node_queue *queue);
        bin_node *(*get_position)(struct bin_node_queue *queue,int n);
}bin_node_queue;

int bin_node_queue_isempty(bin_node_queue * queue);
int bin_node_queue_isfull(bin_node_queue * queue);
int bin_node_queue_enqueue(bin_node_queue *queue,bin_node* value);
bin_node *bin_node_queue_dequeue(bin_node_queue *queue);
bin_node *bin_node_queue_get_tail(struct bin_node_queue *queue);
bin_node *bin_node_queue_get_head(struct bin_node_queue *queue);
bin_node *bin_node_queue_get_position(struct bin_node_queue *queue,int n);
bin_node_queue *bin_node_queue_new(int size);
int bin_node_queue_destroy(bin_node_queue* queue);
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
char *get_position(struct array_queue *queue,int n);
array_queue *array_queue_new(int size);
int array_queue_destroy(array_queue* queue);

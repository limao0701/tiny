typedef struct hash_data{
    long data;
    struct hash_data *pre;
    struct hash_data *sur;
}hash_data;


typedef struct hash_table{
    int size;
    int hash_mode;
    hash_data *data_head;
    int (*insert)(struct hash_table *table,long data);
    int (*remove)(struct hash_table *table,long data);
}hash_table;


hash_table *hash_table_new(int size,int hash_mode);

//insert data to hash table, if exist, not insert and return 0 
int hash_table_insert(hash_table *table,long data);

//remove data from hash table, if not exist, return 0 
int hash_table_remove(hash_table *table,long data);

hash_data * data_list_find(hash_data * head,long data);

void data_list_insert(hash_data * head,long data);

int data_list_remove(hash_data * head,long data);
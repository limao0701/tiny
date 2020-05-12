#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


hash_table *hash_table_new(int size,int hash_mode){
    hash_table *table=(hash_table *)malloc(sizeof(hash_table));
    table->size=size;
    table->hash_mode=hash_mode;
    table->insert=hash_table_insert;
    table->remove=hash_table_remove;
    table->data_head=(hash_data *)malloc(sizeof(hash_data)*hash_mode);
    for(int i=0;i<hash_mode;i++){
        (table->data_head+i)->pre=table->data_head+i;
        (table->data_head+i)->sur=NULL;
    }
    return table;
}


//insert data to hash table, if exist, not insert and return 0 
int hash_table_insert(hash_table *table,long data){
        
    long hash_index=data % table->hash_mode;
    hash_data *data_head=table->data_head+hash_index;
    hash_data *new_data_ptr=(hash_data *)malloc(sizeof(hash_data));
    if(!(data_head->sur)){
        data_head->sur=new_data_ptr;
        new_data_ptr->sur=NULL;
        new_data_ptr->pre=data_head;
        new_data_ptr->data=data;
        return 1;
        
    }
    else{
        if(!data_list_find(data_head->sur,data)){
            data_list_insert(data_head,data);
            return 1;
        }
        free(new_data_ptr);
        return 0;
    }

}

//remove data from hash table, if not exist, return 0 
int hash_table_remove(hash_table *table,long data){
    long hash_index=data % table->hash_mode;
    hash_data *data_head=table->data_head+hash_index;
    return data_list_remove(data_head,data);
}

hash_data * data_list_find(hash_data * head,long data){
    if (!head){
        return NULL;
    }
    if(head->data == data){
        return head;
    }
    return data_list_find(head->sur,data);
}


void data_list_insert(hash_data * head,long data){
    hash_data* new_hash_data=(hash_data *)malloc(sizeof(hash_data));
    new_hash_data->data=data;
    new_hash_data->pre=head;
    new_hash_data->sur=head->sur;
    if(new_hash_data->sur){
        new_hash_data->sur->pre=new_hash_data;
    }
    head->sur=new_hash_data;
    return;
}

int data_list_remove(hash_data * head,long data){
    if(!head->sur){
        return 0;
    }
    hash_data *remove_data_ptr=data_list_find(head->sur,data);
    if(remove_data_ptr){
        (remove_data_ptr->pre)->sur=remove_data_ptr->sur;
        if(remove_data_ptr->sur){
            (remove_data_ptr->sur)->pre=remove_data_ptr->pre;
        }
        free(remove_data_ptr);
        return 1;
    }
    return 0;

}





/*

//insert node as ordered tree,left small than root, right larger than root
int bin_tree_insert_inorder_unique(struct bin_node *root,struct bin_node *node){
    if(!root){
        return 0;
    }
    if(node->data == root->data){
        return 0;
    }
    if(node->data < root->data){
        if(!root->l_child){
            root->l_child=node;
            return 1;
        }
        return bin_tree_insert_inorder_unique(root->l_child,node);
    }
    else{
        if(!root->r_child){
            root->r_child=node;
            return 1;
        }
        return bin_tree_insert_inorder_unique(root->r_child,node);
    }
}

bin_node *  bin_node_find(bin_node *root,long data){
    if(!root){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    if(root->data < data){
        bin_node *find_in_r=bin_tree_find(root->r_child,data);
        if(find_in_r){
            return find_in_r;
        }
    }
    if(data < root->data){
        bin_node *find_in_l=bin_tree_find(root->l_child,data);
        if(find_in_l){
            return find_in_l
        }
    }
    return NULL;
 
}

*/
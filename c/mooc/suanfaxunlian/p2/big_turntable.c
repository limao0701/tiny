#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  bin_node{
    unsigned int data;
    struct  bin_node * parent;
    struct  bin_node * l_child;
    struct  bin_node * r_child;
    int is_l_dead;
    int is_r_dead;
    int depth;
    int height;
    int (*insert_left)(struct  bin_node *,int data);
    int (*insert_right)(struct  bin_node *,int data);

}bin_node_t;

int insert_left(struct  bin_node *,int data,int n);
int insert_right(struct  bin_node *,int data,int n);
int is_data_in_parent(struct  bin_node *node,int data);
int insert_children(struct  bin_node *root,int n);

int main(){
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
//有问题，等待修复
    unsigned int length=(~((unsigned int)0));
    bin_node_t *root=(bin_node_t *)malloc(sizeof(bin_node_t));
    root->data=0;
    root->depth=0;
    root->height=0;
    root->is_l_dead=1;
    root->is_r_dead=1;
    root->l_child=NULL;
    root->r_child=NULL;
    root->parent=NULL;
    insert_children(root,n);
    bin_node_t *node=root;
    while(node){
        printf("%d",node->data&1);
        if(node->is_l_dead){
            node=node->r_child;
        }
        else{
            node=node->l_child;
        }

    }
    return 0;
}



int insert_left(struct  bin_node *node,int data,int n){
    data=data&(~(1<<n));
//printf("inset Left %d on %d\n",data,node->data);
    if(is_data_in_parent(node,data)){
        node->is_l_dead=1;
        return 0;
    }
    bin_node_t *l_node=(bin_node_t *)malloc(sizeof(bin_node_t));
    l_node->data=data;
    l_node->depth=node->depth+1;
    l_node->height=0;
    l_node->is_l_dead=1;
    l_node->is_r_dead=1;
    l_node->l_child=NULL;
    l_node->r_child=NULL;
    l_node->parent=node;
    node->is_l_dead=0;
    node->l_child=l_node;
    return 1;
}
int insert_right(struct  bin_node *node,int data,int n){
    data=data&(~(1<<n));
//printf("inset Right %d on %d\n",data,node->data);
    if(is_data_in_parent(node,data)){
        node->is_r_dead=1;
        return 0;
    }
    bin_node_t *r_node=(bin_node_t *)malloc(sizeof(bin_node_t));
    r_node->data=data;
    r_node->depth=node->depth+1;
    r_node->height=0;
    r_node->is_l_dead=1;
    r_node->is_r_dead=1;
    r_node->l_child=NULL;
    r_node->r_child=NULL;
    r_node->parent=node;
    node->r_child=r_node;
    node->is_r_dead=0;
    return 1;
}

int is_data_in_parent(struct  bin_node *node,int data){
//printf("Check %d in parents\n",data);
    while(node){
        if(node->data==data){
            return 1;
        }
        node=node->parent;
    }
    return 0;
}


int insert_children(struct  bin_node *root,int n){
//printf("inset Children\n");
    int depth=(((unsigned int)1)<<n)-1;
    if(root->depth==depth){
        return depth;
    }
    int root_depth=0;
    int l_depth=0;
    int r_depth=0;
    if(insert_left(root,(root->data<<1) + 0,n)){
        l_depth=insert_children(root->l_child,n);
    }
    if(l_depth==depth){
        return l_depth;
    }
    if(insert_right(root,(root->data<<1) + 1,n)){
        r_depth=insert_children(root->r_child,n);
    }
    if(r_depth==depth){
        return r_depth;
    }

    if(root->is_l_dead && root->is_r_dead &&root->parent){
        if(root->parent->l_child==root){
            root->parent->is_l_dead=1;
            root->parent->l_child=NULL;
        }
        else{
            root->parent->is_r_dead=1;
            root->parent->r_child=NULL;
        }
        root_depth=root->depth;
        free(root);
    }
    return root_depth;
}
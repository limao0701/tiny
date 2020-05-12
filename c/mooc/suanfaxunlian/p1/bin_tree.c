#include<stdio.h>
#include<stdlib.h>
#include"bin_tree.h"

//Method for bin_node

bin_node * bin_node_new(int data){
    bin_node*node=(bin_node *)malloc(sizeof(bin_node));
    node->data=data;
    node->height=0;
    node->r_child=NULL;
    node->l_child=NULL;
    node->insert_left=bin_node_insert_left;
    node->insert_right=bin_node_insert_right;
    node->remove_left=bin_node_remove_left;
    node->remove_right=bin_node_remove_right;
    node->update_height=bin_node_update_height;
    return node;
}

int bin_node_update_height(struct bin_node *node){
    int l_height=0;
    int r_height=0;
    if(node->l_child){
        l_height=node->l_child->height;
    }
    if(node->r_child){
        r_height=node->r_child->height;
    }
    node->height=1+((l_height<r_height)?r_height:l_height);
    return node->height;
}

int bin_node_insert_left(struct bin_node *node,struct bin_node *node_left){
    if(node->l_child){
        printf("Left not NULL\n");
        return 0;
    }
    node->l_child=node_left;
    return 1;

}
int bin_node_insert_right(struct bin_node *node,struct bin_node *node_right){
    if(node->r_child){
        printf("Right not NULL\n");
        return 0;
    }
    node->r_child=node_right;
    return 1;

}
int bin_node_remove_left(struct bin_node *node,int free_it){
    if(!node->l_child){
        printf("Left is NULL\n");
        return 0;
    }
    if(free_it){
        free(node->l_child);
    }
    node->l_child=NULL;
    return 1;
}
int bin_node_remove_right(struct bin_node *node,int free_it){
    if(!node->r_child){
        printf("Right is NULL\n");
        return 0;
    }
    if(free_it){
        free(node->r_child);
    }
    node->r_child=NULL;
    return 1;
}

int update_height(struct bin_node *node){
    int height=node->height;
    if(node->l_child){
        height=node->l_child->height+1;
    }
    if(node->r_child){
        node->height=node->r_child->height+1;
    }
    node->height=(node->height<height)?height:node->height;
    return 1;
}

//a>b?
int bin_node_large(bin_node *a,bin_node *b){
    return b->data < a->data;
}

//a<b?
int bin_node_less(bin_node *a,bin_node *b){
    return a->data < b->data;
}

//a==b?
int bin_node_equal(bin_node *a,bin_node *b){
    return a->data == b->data;
}



//These methods are for bintree
bin_tree *bin_tree_new(bin_node * root){
    bin_tree *tree=malloc(sizeof(bin_tree));
    tree->root=root;
    tree->size=(root!=NULL);
    tree->get_root=bin_tree_get_root;
    tree->insert_root=bin_tree_insert_root;
    tree->insert_left=bin_tree_insert_left;
    tree->insert_right=bin_tree_insert_right;
    tree->remove_left=bin_tree_remove_left;
    tree->remove_right=bin_tree_remove_right;
    tree->trav_ino=bin_tree_trav_ino;
    tree->trav_pre=bin_tree_trav_pre;
    tree->trav_pos=bin_tree_trav_pos;
    tree->trav_level=bin_tree_trav_level;
    return tree;
}

int bin_tree_isempty(bin_tree *tree){
    return (!tree->size);
}

struct bin_node *bin_tree_get_root(bin_tree *tree){
    return tree->root;
}

int  bin_tree_insert_root(bin_tree *tree,struct bin_node *node){
    tree->root=node;
    return 1;
}

int  bin_tree_insert_left(bin_tree *tree,struct bin_node *node){
    return 1;
}

int  bin_tree_insert_right(bin_tree *tree,struct bin_node *node){
    return 1;
}

int  bin_tree_remove_left(bin_tree *tree){
    return 1;
}

int  bin_tree_remove_right(bin_tree *treede){
    return 1;
}

void bin_tree_trav_pre(bin_node *root,void(*trave_fun)(bin_node *node)){
    if(!root){      
        return;
    }

    trave_fun(root);
    bin_tree_trav_pre(root->l_child,trave_fun);
    bin_tree_trav_pre(root->r_child,trave_fun);
    return;
}

void bin_tree_trav_ino(bin_node *root,void(*trave_fun)(bin_node *node)){
    if(!root){
        return;
    }
    bin_tree_trav_ino(root->l_child,trave_fun);
    trave_fun(root);
    bin_tree_trav_ino(root->r_child,trave_fun);
    return;
}
void bin_tree_trav_pos(bin_node *root,void(*trave_fun)(bin_node *node)){
    if(!root){
        return;
    }
    bin_tree_trav_pos(root->l_child,trave_fun);
    bin_tree_trav_pos(root->r_child,trave_fun);
    trave_fun(root);
    return;
}

void bin_tree_trav_level(bin_node *root,void(*trave_fun)(bin_node *node)){
    if(!root){
        return;
    }
    //trave_fun(root);
    return;
}
//insert node as ordered tree,left small than root, right larger than root
void bin_tree_insert_inorder(struct bin_node *root,struct bin_node *node){
    if(!root){
        return;
    }
    if(node->data < root->data){
        if(!root->l_child){
            root->l_child=node;
            return;
        }
        bin_tree_insert_inorder(root->l_child,node);
        return;
    }
    else{
        if(!root->r_child){
            root->r_child=node;
            return;
        }
        bin_tree_insert_inorder(root->r_child,node);
        return;
    }
}
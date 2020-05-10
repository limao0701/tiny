#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"bin_tree.h"

void static trave_fun(bin_node *node);
int main(){
    /*        
	srand(time(NULL));
	unsigned int max_len=1;
	scanf("%u",&max_len);
    unsigned int n=max_len;
    unsigned int a[n];
    for(unsigned int i=0;i<n;i++){
		a[i]=(unsigned int)rand()%100001;
		//printf("%u\n",a[i]);
	}
    bin_node *root_node = bin_node_new(a[0]);
    bin_tree *my_tree=bin_tree_new(root_node);
    bin_node *tmp_node=NULL;
    for(int i=1;i<n;i++){
        tmp_node = bin_node_new(a[i]);
        bin_tree_insert_inorder(my_tree->root,tmp_node);
    }
   */


///*
    int n=0;
    int data=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    scanf("%d",&data);
    bin_node *root_node = bin_node_new(data);
    bin_tree *my_tree=bin_tree_new(root_node);
    bin_node *tmp_node=NULL;
    for(int i=1;i<n;i++){
        scanf("%d",&data);
        tmp_node = bin_node_new(data);
        bin_tree_insert_inorder(my_tree->root,tmp_node);
    }
//*/

    bin_tree_trav_pre(root_node,trave_fun);
    //my_tree->trav_pre(my_tree->root,trave_fun);
    printf("\n");
    bin_tree_trav_pos(root_node,trave_fun);
    //my_tree->trav_pos(my_tree->root,trave_fun);
}

void trave_fun(bin_node *node){
    if(!node){
        return;
    }
    printf("%d ",node->data);
    return;
}
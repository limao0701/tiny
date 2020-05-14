#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"equation.h"


int main(){
    int n=0;
    scanf("%d",&n);
    if(!n){
        return 0;
    }
    int var_number=0;
    int con_number=0;
    int is_equal=0;
    int var1=0;
    int var2=0;
    int equal_i=0;
    int unqeual_i=0;
    char **results=(char **)malloc(sizeof(char *) * n);
next_group:
    for(int i=0;i<n;i++){
        scanf("%d",&var_number);
        scanf("%d",&con_number);
        int *var_head=(int *)malloc((sizeof(int)) * (var_number+1));
        int *unequal_head=(int *)malloc((sizeof(int))*(2*(var_number+1)));
        unqeual_i=0;
        for(int j=0;j<=var_number;j++){
            var_head[j]=j;
        }
        for(int j=0;j<con_number;j++){
input:
            scanf("%d",&var1);
            scanf("%d",&var2);
            scanf("%d",&is_equal);
            if(is_equal){
                union_vars(var_head,var2,var1);
            }
            else{
                /*if(find_union_var_root(var_head,unequal_head[j])==find_union_var_root(var_head,unequal_head[j+1])){
                    results[i]="No";
                    //goto input;
                }*/
                unequal_head[unqeual_i]=var1;
                unqeual_i++;
                unequal_head[unqeual_i]=var2;
                unqeual_i++;
            }

        }
        for(int j=0;j<unqeual_i;){
            if(find_union_var_root(var_head,unequal_head[j])==find_union_var_root(var_head,unequal_head[j+1])){
                results[i]="No";
                goto free_all;

            }
            j+=2;
        }
        results[i]="Yes";
free_all:
        free(var_head);
        free(unequal_head);

    }
    for(int i=0;i<n;i++){
        printf("%s\n",results[i]);
    }


    /*
    group_t *groups_head=(group_t *)malloc(sizeof(group_t) * (size_t)n);
    for(int i=0;i<n;i++){
        equal_i=0;
        unqeual_i=0;
        scanf("%d",&var_number);
        scanf("%d",&con_number);
        (groups_head+i)->var_number=var_number;
        (groups_head+i)->con_number=con_number;
        (groups_head+i)->equal_cond_number=0;
        (groups_head+i)->unequal_cond_number=0;
        (groups_head+i)->equal_con_head=(condition_t *)malloc(sizeof(condition_t) * (size_t)con_number);
        (groups_head+i)->unequal_con_head=(condition_t *)malloc(sizeof(condition_t) * (size_t)con_number);
        (groups_head+i)->par_head=(parent_t *)malloc(sizeof(parent_t) * (size_t)var_number);
        for(int j=0;j<var_number;j++){
            ((groups_head+i)->par_head+j)->data=j+1;
            ((groups_head+i)->par_head+j)->parent=j+1;
        }
        for(int j=0;j<con_number;j++){
            scanf("%d",&var1);
            scanf("%d",&var2);
            scanf("%d",&is_equal);
            if(is_equal){
                (((groups_head+i)->equal_con_head)+equal_i)->var_1=var1;
                ((groups_head+i)->equal_con_head+equal_i)->var_2=var2;
                ((groups_head+i)->equal_con_head+equal_i)->condition=is_equal;
                (groups_head+i)->equal_cond_number++;
                equal_i++;
            }
            else{
                ((groups_head+i)->unequal_con_head+unqeual_i)->var_1=var1;
                ((groups_head+i)->unequal_con_head+unqeual_i)->var_2=var2;
                ((groups_head+i)->unequal_con_head+unqeual_i)->condition=is_equal;
                (groups_head+i)->unequal_cond_number++;
                unqeual_i++;

            }
            
        }
        
    }
    //print_all(groups_head,n);
    update_parent(groups_head,n);
    //print_all(groups_head,n);
    for(int i=0;i<n;i++){
        print_results(groups_head+i);
    }
    */
    return 0;
}

void print_all(group_t* group,int n){
    char *iseq[2]={"!=","=="};
    for(int i=0;i<n;i++){
        printf("Group: %d\n",i+1);
        for(int j=0;j<(group+i)->var_number;j++){
            printf("Variables:\n");
            printf("%d points to %d\n",((group+i)->par_head+j)->data,((group+i)->par_head+j)->parent);
            printf("%d root points to %d\n",((group+i)->par_head+j)->data,find_top_parent((group+i)->par_head,((group+i)->par_head+j)->data));
        }
        for(int j=0;j<(group+i)->equal_cond_number;j++){
            printf("Equal Conditions:\n");
            printf("%d %s %d\n",((group+i)->equal_con_head+j)->var_1,
                                iseq[1],
                                ((group+i)->equal_con_head+j)->var_2);
        }
        for(int j=0;j<(group+i)->unequal_cond_number;j++){
            printf("Unequal Conditions:\n");
            printf("%d %s %d\n",((group+i)->unequal_con_head+j)->var_1,
                                iseq[0],
                                ((group+i)->unequal_con_head+j)->var_2);
        }
    }

}


void update_parent(group_t* group,int n){
    for (int i=0;i<n;i++){
    condition_t *equal_head=(group+i)->equal_con_head;
    int equal_numbers=(group+i)->equal_cond_number;
    parent_t *parent_head=(group+i)->par_head;
    for(int i=0;i<equal_numbers;i++){
       (parent_head+((equal_head+i)->var_2 - 1))->parent = (equal_head+i)->var_1;    
    }
    }
}


int find_top_parent(parent_t *parent_head,int number){
    if((parent_head+number-1)->parent == (parent_head+number-1)->data){
        return number;
    }
    return find_top_parent(parent_head,(parent_head+number-1)->parent);
}


void print_results(group_t *group){
    parent_t *parent=group->par_head;
    condition_t *unequal_h=group->unequal_con_head;
    int unequal_num=group->unequal_cond_number;
    for(int i=0;i<unequal_num;i++){
        if(find_top_parent(parent,(unequal_h+i)->var_1) == find_top_parent(parent,(unequal_h+i)->var_2)){
            printf("No\n");
            return;
        }
        
    }
    printf("Yes\n");
}



void union_vars(int a[],int var,int parent){
    int root=find_union_var_root(a,parent); //不能出现环路
    a[var]=root;
}

int find_union_var_root(int a[],int var){
 //   printf("Finding %d\n",var);
 //   printf("Array[%d] is %d\n",a[var],var);
    if(a[var]==var){
        return var; 
    }
    else{
        return find_union_var_root(a,a[var]);
    }
}
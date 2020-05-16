#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct i_road{
    int city1;
    int city2;
    int prio;
}i_road_t;
int find_union_var_root(int a[],int var);
void union_vars(int a[],int var,int parent);

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
        return a[var]=find_union_var_root(a,a[var]);//路径压缩
    }
}

void road_sort(i_road_t *roads_head,int n);

int main(){
    int city_num=0;
    int road_num=0;
    int city_1=0;
    int city_2=0;
    scanf("%d",&city_num);
    scanf("%d",&road_num);
    if(!road_num ||!city_num){
        return 0;
    }
    int *city_point_to_next=(int *)malloc((sizeof(int)) * (city_num+1));
    i_road_t *all_roads=(i_road_t *)malloc((sizeof(i_road_t)) * (road_num+1));
    for(int j=0;j<=city_num;j++){
        city_point_to_next[j]=j;  //先全部指向自己
    }
    all_roads[0].city1=0;
    all_roads[0].city2=0;
    all_roads[0].prio=0;
    for(int i=1;i<=road_num;i++){
        scanf("%d",&city_1);
        scanf("%d",&city_2);
        all_roads[i].city1=city_1;
        all_roads[i].city2=city_2;
        all_roads[i].prio=i;
        //inpute each road related city_num;
    }
    //sort all roads

    //printf("sorting\n");
    //road_sort(all_roads+1,road_num);
    //printf("end sorting\n");
    int how_many_roads=0;
    //push good road into road_numbers[how_many_roads]
    int *road_numbers=(int *)malloc((sizeof(int)) * road_num);


//遍历的方式太慢？？


        for(int i=road_num;i>=1;i--){
            if( find_union_var_root(city_point_to_next,(all_roads+i)->city1) ==
                find_union_var_root(city_point_to_next,(all_roads+i)->city2) ){
                   continue;
               }
               else{
                   union_vars(city_point_to_next,
                        find_union_var_root(city_point_to_next,(all_roads+i)->city2),
                        (all_roads+i)->city1);
                   road_numbers[how_many_roads]=(all_roads+i)->prio;
                   how_many_roads++;
               }
            if(how_many_roads==city_num-1){
                break;
            }
        }

    printf("%d\n",how_many_roads);
    for(int i=how_many_roads-1;i>=0;i--){
        printf("%d\n",road_numbers[i]);
    }
    
}


void road_sort(i_road_t *roads_head,int n){
    int sorted=1;
    int reversed=0;
    int right_sorted=n-1;
    i_road_t tmp;
    n--;
    do{
        //n--;
        //printf("n=%d\n",n);
        sorted=1;
        for(int i=0;i<n;i++){
            if(roads_head[i].prio < roads_head[i+1].prio){  //从大到小排序
                tmp=roads_head[i];
                roads_head[i]=roads_head[i+1];
                roads_head[i+1]=tmp;
                sorted=0;
                right_sorted=i;
            }

        }
        n=right_sorted;
    }while(!sorted);
    return;
}
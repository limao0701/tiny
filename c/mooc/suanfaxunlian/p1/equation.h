typedef struct group{
    int var_number;
    int con_number;
    int equal_cond_number;
    int unequal_cond_number;
    struct condition *equal_con_head;
    struct condition *unequal_con_head;
    struct parent* par_head;
}group_t;

typedef struct parent{
    int parent;
    int data;
}parent_t;

typedef struct condition{
    int var_1;
    int var_2;
    int condition;
}condition_t;

typedef struct unequal{
    condition_t *condition;
    struct unequal *next;
}unequal_t;

void update_parent(group_t* group, int n);
void print_all(group_t* group,int n);
int find_top_parent(parent_t *parent_head,int number);
void print_results(group_t*groups_head);

void union_vars(int a[],int var,int parent);
int find_union_var_root(int a[],int var);
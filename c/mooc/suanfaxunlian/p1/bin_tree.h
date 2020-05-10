typedef struct bin_node{
    struct bin_node * parent;
    struct bin_node * l_child;
    struct bin_node * r_child;
    int data;
    int (*insert_left)(struct bin_node *node,struct bin_node *node_left);
    int (*insert_right)(struct bin_node *node,struct bin_node *node_right);
    int (*remove_left)(struct bin_node *node,int free_it);
    int (*remove_right)(struct bin_node *node,int free_it);
    int height;
    int (*update_height)(struct bin_node *node);
}bin_node;

typedef struct bin_tree{
    bin_node*root;
    int size;
    int (*isempty)(struct bin_tree *tree);
    struct bin_node *(*get_root)(struct bin_tree *tree);
    int (*insert_root)(struct bin_tree *tree,struct bin_node *node);
    int (*insert_left)(struct bin_tree *tree,struct bin_node *node);
    int (*insert_right)(struct bin_tree *tree,struct bin_node *node);
    int (*remove_left)(struct bin_tree *tree);
    int (*remove_right)(struct bin_tree *tree);
    void(*trav_pre)( bin_node *root,void(*trave_fun)(bin_node *node));
    void(*trav_ino)( bin_node *root,void(*trave_fun)(bin_node *node));
    void(*trav_pos)( bin_node *root,void(*trave_fun)(bin_node *node));
    void(*trav_level)( bin_node *root,void(*trave_fun)(bin_node *node));
}bin_tree;

bin_node * bin_node_new(int data);
int bin_node_insert_left(struct bin_node *node,struct bin_node *node_left);
int bin_node_insert_right(struct bin_node *node,struct bin_node *node_right);
int bin_node_remove_left(struct bin_node *node,int free_it);
int bin_node_remove_right(struct bin_node *node, int free_it);
int update_height(struct bin_node *node);

bin_tree *bin_tree_new(bin_node * root);
int bin_tree_isempty(bin_tree *tree);
struct bin_node *bin_tree_get_root(bin_tree *tree);
int  bin_tree_insert_root(bin_tree *tree,struct bin_node *node);
int  bin_tree_insert_left(bin_tree *tree,struct bin_node *node);
int  bin_tree_insert_right(bin_tree *tree,struct bin_node *node);
int  bin_tree_remove_left(bin_tree *tree);
int  bin_tree_remove_right(bin_tree *tree);
void bin_tree_insert_inorder(struct bin_node *root,struct bin_node *node);
void bin_tree_trav_pre( bin_node *root,void(*trave_fun)(bin_node *node));
void bin_tree_trav_ino( bin_node *root,void(*trave_fun)(bin_node *node));
void bin_tree_trav_pos( bin_node *root,void(*trave_fun)(bin_node *node));
void bin_tree_trav_level( bin_node *root,void(*trave_fun)(bin_node *node));



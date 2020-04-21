typedef struct _node
{
    int key;
    struct _node *left, *right;
} node;
node* crnode(int val)
{
    node* nnode = (node*) malloc(sizeof(node));
    nnode->key = val;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}
node* add_tree(node *root, int val)
{
    if (NULL == root) root = crnode(val);
    if (val < root->key)
    {
        if (NULL == root->left)
            root->left = crnode(val);
        else
            add_tree(root->left, val);
    }
    if (val > root->key)
    {
        if (NULL == root->right)
            root->right = crnode(val);
        else
            add_tree(root->right, val);
    }
    return root;
}
int node_height(const node* root)
{
    int l, r, h = 0;
    if(root != NULL)
    {
        l = node_height(root -> left);
        r = node_height(root -> right);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}
void print_tree(node *root)
{
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->key);
        print_tree(root->right);
    }
}

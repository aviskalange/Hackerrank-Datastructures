/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node *rotatel(node *root)
{
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    int l,r;
    l=r=0;
    if(root->left!=NULL)
        l=root->left->ht+1;
    if(root->right!=NULL)
        r=root->right->ht+1;
    root->ht=max(l,r);
    root=temp;
    l=r=0;
    if(root->left!=NULL)
        l=root->left->ht+1;
    if(root->right!=NULL)
        r=root->right->ht+1;
    root->ht=max(l,r);
    return temp;
}

node *rotater(node *root)
{
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    int l,r;
    l=r=0;
    if(root->left!=NULL)
        l=root->left->ht+1;
    if(root->right!=NULL)
        r=root->right->ht+1;
    root->ht=max(l,r);
    root=temp;
    l=r=0;
    if(root->left!=NULL)
        l=root->left->ht+1;
    if(root->right!=NULL)
        r=root->right->ht+1;
    root->ht=max(l,r);
    return temp;
}

node * insert(node * root,int val)
{
    if(root==NULL)
    {
        node *n=new node();
        n->val=val;
        n->left=n->right=NULL;
        n->ht=0;
        return n;
    }
    if(val<root->val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    int l,r;
    l=r=0;
    if(root->left!=NULL)
        l=root->left->ht+1;
    if(root->right!=NULL)
        r=root->right->ht+1;
    root->ht=max(l,r);
    int bf=abs(l-r);
    if(bf>1)
    {
       // cout<<root->val<<" "<<l<<" "<<r<<endl;
        if(val<root->val)
        {
            if(val<root->left->val)
                root=rotater(root);
            else
            {
                root->left=rotatel(root->left);
                root=rotater(root);
            }
        }
        else
        {
            if(val>root->right->val)
                root=rotatel(root);
            else
            {
                root->right=rotater(root->right);
                root=rotatel(root);
            }
        }
    }
    return root;  
}

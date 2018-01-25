/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
   int maxl(Node *ptr)
   {
       if(ptr==NULL)
           return -1;
       int l=maxl(ptr->left);
       int r=maxl(ptr->right);
       l=max(l,ptr->data);
       r=max(r,l);
       return r;
   }

   int minr(Node *ptr)
   {
       if(ptr==NULL)
           return 99999;
       int l=minr(ptr->left);
       int r=minr(ptr->right);
       l=min(l,ptr->data);
       r=min(r,l);
       return r;
   }

   bool checkBST(Node* root) 
   {
       Node* s[10000];
       int cnt=-1;
       Node *ptr=root;
       while(cnt!=-1||ptr!=NULL)
       {
           while(ptr!=NULL)
           {
               s[++cnt]=ptr;
               ptr=ptr->left;
           }
           ptr=s[cnt--];
           int l=maxl(ptr->left);
           int r=minr(ptr->right);
           if(!(ptr->data>l&&ptr->data<r))
               return false;
           ptr=ptr->right;
       }
       return true;
   }

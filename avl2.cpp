#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

//function to find height of tree
int height(struct node *temp)
{
    if(temp==NULL)
        return 0;
    return temp->height;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}



node* newnode(int data)
{
    struct node *temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}

node* rightrotate(struct node *y)   //T1, T2, T3 and T4 are subtrees.
    /**  z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2 **/
{
    struct node *x=y->left;
    struct node *t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

node* leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct node *t2=y->left;
    y->left=x;
    x->right=t2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
/*
  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4   */
}

int getbalance(struct node *temp)
{
    if(temp==NULL)
        return 0;
    return height(temp->left)-height(temp->right);
}

node* insert(struct node *temp,int data)
{
    if(temp==NULL)
        return newnode(data);
    if(data<temp->data)
        temp->left=insert(temp->left,data);
    else if(data>temp->data)
        temp->right=insert(temp->right,data);
    else
        return temp;
    temp->height=1+max(height(temp->left),height(temp->right));
    int balance=getbalance(temp);
    if(balance>1 && data<temp->left->data)
        return rightrotate(temp);
    if(balance<-1 && data>temp->right->data)
        return leftrotate(temp);
    if(balance>1 && data>temp->left->data)
    {
        temp->left=leftrotate(temp->left);
        return rightrotate(temp);
    }
    if(balance<-1 && data<temp->right->data)
    {
        temp->right=rightrotate(temp->right);
        return leftrotate(temp);
    }
    return temp;
}

void deleteNode(struct node* root, int key) 
{ 
    struct node* temp = root; 
    struct node* parent = NULL; 
    while (temp != NULL && temp->data != key) { 
        parent = temp; 
        if (key < temp->data) 
            temp = temp->left; 
        else
            temp = temp->right; 
    } 
    if (temp == NULL) 
        return; 
    if (temp->left == NULL && temp->right == NULL) { 
        if (temp != root) { 
            if (parent->left == temp) 
                parent->left = NULL; 
            else
                parent->right = NULL; 
        } 
        else
            root = NULL; 
        free(temp); 
    } 
    else if (temp->left && temp->right) { 
        struct node* succParent = temp; 
        struct node* succ = temp->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
        if (succParent != temp) 
            succParent->left = succ->right; 
        else
            succParent->right = succ->right; 
        temp->data = succ->data; 
        free(succ); 
    } 
    else { 
        struct node* child = (temp->left)? temp->left: temp->right; 
        if (temp != root) { 
            if (temp == parent->left) 
                parent->left = child; 
            else
                parent->right = child; 
        } 
        else
            root = child; 
        free(temp); 
    } 
}

void search(struct node *temp,int data)
{
    if(temp==NULL)
    {
        cout<<"Not found"<<endl;
        return;
    }
    if(temp->data==data)
    {
        cout<<"Found"<<endl;
        return;
    }
    if(data<temp->data)
        search(temp->left,data);
    else
        search(temp->right,data);
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void levelorder(struct node *root)
{
    if(root==NULL)
        return;
    queue<struct node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main()
{
    struct node *root=NULL;
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter nodes: ";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root=insert(root,x);
    }
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder: ";
    levelorder(root);
    cout<<endl;
    cout<<"Enter node to be deleted: ";
    int x;
    cin>>x;
    deleteNode(root,x);
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder: ";
    levelorder(root);
    cout<<endl;
    cout<<"Enter node to be searched: ";
    cin>>x;
    search(root,x);
    return 0;
}


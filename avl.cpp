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

class avl
{
    public:
        struct node *root;
        avl()
        {
            root=NULL;
        }
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
        struct node *newnode(int data)
        {
            struct node *temp=new node;
            temp->data=data;
            temp->left=NULL;
            temp->right=NULL;
            temp->height=1;
            return temp;
        }
        struct node *rightrotate(struct node *y)
        {
            struct node *x=y->left;
            struct node *t2=x->right;
            x->right=y;
            y->left=t2;
            y->height=max(height(y->left),height(y->right))+1;
            x->height=max(height(x->left),height(x->right))+1;
            return x;
        }
        struct node *leftrotate(struct node *x)
        {
            struct node *y=x->right;
            struct node *t2=y->left;
            y->left=x;
            x->right=t2;
            x->height=max(height(x->left),height(x->right))+1;
            y->height=max(height(y->left),height(y->right))+1;
            return y;
        }
        int getbalance(struct node *temp)
        {
            if(temp==NULL)
                return 0;
            return height(temp->left)-height(temp->right);
        }
        struct node *insert(struct node *temp,int data)
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
        void inorder(struct node *temp)
        {
            if(temp!=NULL)
            {
                inorder(temp->left);
                cout<<temp->data<<" ";
                inorder(temp->right);
            }
        }   
        void preorder(struct node *temp)
        {
            if(temp!=NULL)
            {
                cout<<temp->data<<" ";
                preorder(temp->left);
                preorder(temp->right);
            }
        }
        void postorder(struct node *temp)
        {
            if(temp!=NULL)
            {
                postorder(temp->left);
                postorder(temp->right);
                cout<<temp->data<<" ";
            }
        }

        void levelorder(struct node *temp)
        {
            if(temp==NULL)
                return;
            queue<struct node *> q;
            q.push(temp);
            while(!q.empty())
            {
                struct node *node=q.front();
                cout<<node->data<<" ";
                q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        void search(struct node *temp,int data)
        {
            if(temp==NULL)
            {
                cout<<"Not found\n";
                return;
            }
            if(temp->data==data)
            {
                cout<<"Found\n";
                return;
            }
            if(data<temp->data)
                search(temp->left,data);
            else
                search(temp->right,data);
        }
        struct node *minvalue(struct node *temp)
        {
            struct node *current=temp;
            while(current->left!=NULL)
                current=current->left;
            return current;
        }
        struct node *deleteNode(struct node *root,int data)
        {
            if(root==NULL)
                return root;
            if(data<root->data)
                root->left=deleteNode(root->left,data);
            else if(data>root->data)
                root->right=deleteNode(root->right,data);
            else
            {
                if(root->left==NULL || root->right==NULL)
                {
                    struct node *temp=root->left?root->left:root->right;
                    if(temp==NULL)
                    {
                        temp=root;
                        root=NULL;
                    }
                    else
                        *root=*temp;
                    free(temp);
                }
                else
                {
                    struct node *temp=minvalue(root->right);
                    root->data=temp->data;
                    root->right=deleteNode(root->right,temp->data);
                }
            }
            if(root==NULL)
                return root;
            root->height=1+max(height(root->left),height(root->right));
            int balance=getbalance(root);
            if(balance>1 && getbalance(root->left)>=0)
                return rightrotate(root);
            if(balance>1 && getbalance(root->left)<0)
            {
                root->left=leftrotate(root->left);
                return rightrotate(root);
            }
            if(balance<-1 && getbalance(root->right)<=0)
                return leftrotate(root);
            if(balance<-1 && getbalance(root->right)>0)
            {
                root->right=rightrotate(root->right);
                return leftrotate(root);
            }
            return root;
        }
};

int main()
{
    avl tree;
    int ch,data;
    while(1)
    {
        cout<<"1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Levelorder\n8.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter data\n";
                cin>>data;
                tree.root=tree.insert(tree.root,data);
                break;
            case 2:
                cout<<"Enter data\n";
                cin>>data;
                tree.root=tree.deleteNode(tree.root,data);
                break;
            case 3:
                cout<<"Enter data\n";
                cin>>data;
                tree.search(tree.root,data);
                break;
            case 4:
                tree.inorder(tree.root);
                cout<<endl;
                break;
            case 5:
                tree.preorder(tree.root);
                cout<<endl;
                break;
            case 6:
                tree.postorder(tree.root);
                cout<<endl;
                break;
            case 7:
                tree.levelorder(tree.root);
                cout<<endl;
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}
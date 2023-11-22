#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node* inorder(node *root)
{
    if(root->left!=NULL)
        inorder(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL)
        inorder(root->right);
}
node* preorder(node *root)
{
    cout<<root->data<<" ";
    if(root->left!=NULL)
        preorder(root->left);
    if(root->right!=NULL)
        preorder(root->right);
}
node* postorder(node *root)
{
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    cout<<root->data<<" ";
}
node* levelorder(node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        node *queue[100];
        int front=0,rear=0;
        queue[rear++]=root;
        while(front!=rear)
        {
            node *temp=queue[front++];
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                queue[rear++]=temp->left;
            if(temp->right!=NULL)
                queue[rear++]=temp->right;
        }
    }
}
node* insert(node *root,int data)
{
    if(root==NULL)
    {
        node *temp=new node;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
    }
    else if(data<=root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
node* search(node *root,int data)
{
    if(root==NULL)
        return NULL;
    else if(root->data==data)
        return root;
    else if(data<=root->data)
        return search(root->left,data);
    else
        return search(root->right,data);
} 

node* findmin(node *root)
{
    if(root->left==NULL)
        return root;
    else
        return findmin(root->left);
}   

node* del(node *root,int data)
{
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left=del(root->left,data);
    else if(data>root->data)
        root->right=del(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
    }
    return root;
}   

node* findmax(node *root)
{
    if(root->right==NULL)
        return root;
    else
        return findmax(root->right);
}   

node* successor(node *root,int data)
{
    node *current=search(root,data);
    if(current==NULL)
        return NULL;
    if(current->right!=NULL)
        return findmin(current->right);
    else
    {
        node *successor=NULL;
        node *ancestor=root;
        while(ancestor!=current)
        {
            if(current->data<ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
                ancestor=ancestor->right;
        }
        return successor;
    }
}

node* predecessor(node *root,int data)
{
    node *current=search(root,data);
    if(current==NULL)
        return NULL;
    if(current->left!=NULL)
        return findmax(current->left);
    else
    {
        node *predecessor=NULL;
        node *ancestor=root;
        while(ancestor!=current)
        {
            if(current->data>ancestor->data)
            {
                predecessor=ancestor;
                ancestor=ancestor->right;
            }
            else
                ancestor=ancestor->left;
        }
        return predecessor;
    }
}

node* lca(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return lca(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return lca(root->right,n1,n2);
    return root;
}   

node* mirror(node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        node *temp;
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    return root;
}

node* copy(node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        node *temp=new node;
        temp->data=root->data;
        temp->left=copy(root->left);
        temp->right=copy(root->right);
        return temp;
    }
}

node* deltree(node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        deltree(root->left);
        deltree(root->right);
        delete root;
    }
    return NULL;
}

node* find(node *root,int data)
{
    if(root==NULL)
        return NULL;
    else if(root->data==data)
        return root;
    else if(data<=root->data)
        return find(root->left,data);
    else
        return find(root->right,data);
}

node* findlca(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca(root->right,n1,n2);
    return root;
}

node* insertbst(node *root,int data)
{
    if(root==NULL)
    {
        node *temp=new node;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
    }
    else if(data<=root->data)
        root->left=insertbst(root->left,data);
    else
        root->right=insertbst(root->right,data);
    return root;
}

node* delbst(node *root,int data)
{
    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left=delbst(root->left,data);
    else if(data>root->data)
        root->right=delbst(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=delbst(root->right,temp->data);
        }
    }
    return root;
}

node* findbst(node *root,int data)
{
    if(root==NULL)
        return NULL;
    else if(root->data==data)
        return root;
    else if(data<=root->data)
        return findbst(root->left,data);
    else
        return findbst(root->right,data);
}

node* findlca1(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca1(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca1(root->right,n1,n2);
    return root;
}

node* findlca2(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca2(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca2(root->right,n1,n2);
    return root;
}

node* findlca3(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca3(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca3(root->right,n1,n2);
    return root;
}

node* findlca4(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca4(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca4(root->right,n1,n2);
    return root;
}

node* findlca5(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca5(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca5(root->right,n1,n2);
    return root;
}

node* findlca6(node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data>n2)
        return findlca6(root->left,n1,n2);
    if(root->data<n1 && root->data<n2)
        return findlca6(root->right,n1,n2);
    return root;
}
int main(){

    node *root=NULL;
    cout<<"Enter the number of nodes in the tree: ";
    int n;
    cin>>n;
    cout<<"Enter the nodes: ";
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        root=insert(root,data);
    }
    node *current=root;
    while (current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->right;
    }    
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder traversal: ";
    levelorder(root);
    cout<<endl;
    cout<<"Enter the node to be searched: ";
    int data;
    cin>>data;
    node *temp=search(root,data);
    if(temp==NULL)
        cout<<"Node not found"<<endl;
    else
        cout<<"Node found"<<endl;
    cout<<"Enter the node to be deleted: ";
    cin>>data;
    root=del(root,data);
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Enter the node whose successor is to be found: ";
    cin>>data;
    node *temp1=successor(root,data);
    if(temp1==NULL)
        cout<<"No successor"<<endl;
    else
        cout<<"Successor: "<<temp1->data<<endl;
    cout<<"Enter the node whose predecessor is to be found: ";
    cin>>data;
    node *temp2=predecessor(root,data);
    if(temp2==NULL)
        cout<<"No predecessor"<<endl;
    else
        cout<<"Predecessor: "<<temp2->data<<endl;
    cout<<"Enter the nodes whose lca is to be found: ";
    int n1,n2;
    cin>>n1>>n2;
    node *temp3=lca(root,n1,n2);
    if(temp3==NULL)
        cout<<"No lca"<<endl;
    else
        cout<<"Lca: "<<temp3->data<<endl;
    cout<<"Mirror image of the tree: ";
    root=mirror(root);
    inorder(root);
    cout<<endl;
    cout<<"Copy of the tree: ";
    node *root1=copy(root);
    inorder(root1);
    cout<<endl;
    cout<<"Enter the node to be searched: ";
    cin>>data;
    node *temp4=find(root,data);
    if(temp4==NULL)
        cout<<"Node not found"<<endl;
    else
        cout<<"Node found"<<endl;
    cout<<"Enter the nodes whose lca is to be found: ";
    cin>>n1>>n2;
    node *temp5=findlca(root,n1,n2);
    if(temp5==NULL)
        cout<<"No lca"<<endl;
    else
        cout<<"Lca: "<<temp5->data<<endl;
    
}
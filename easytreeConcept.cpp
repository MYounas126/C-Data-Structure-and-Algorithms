#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {

        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    node *preorder();
    node *inorder();
    node *postorder();
    node *levelorder();
};

node *preorder(node *root)
{
    if (root == NULL)
    {

        return NULL;
    }

    else
    {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

node *inorder(node *root)
{

    if (root == NULL)
    {

        return NULL;
    }

    else
    {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *postorder(node *root)
{

    if (root == NULL)
    {

        return NULL;
    }

    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

node *levelorder(node *root)
{

    if (root == NULL)
    {

        return NULL;
    }

    else
    {

        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {

            node *current = q.front();
            cout << current->data << " ";
            if (current->left != NULL)
            {

                q.push(current->left);
            }
            if (current->right != NULL)
            {

                q.push(current->right);
            }

            q.pop();
        }
    }
}

node* insert(node* root, int val){

    if(root == NULL){

        return new node(val);

    }

    if(val< root->data){

        root->left = insert(root->left, val);

    }

    if(val> root->data){

        root->right = insert(root->right, val);

    }

    return root;
}

node* search(node* root, int key){

    if(root == NULL){

        return NULL;

    }
    if(root->data == key){

        return root;
    }

    if(key< root->data){

        root->left = search(root->left, key);

    }
    if(key> root->data){

        root->right = search(root->right, key);
    }
}
node* removee(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){

        root->left=removee(root->left,key);
    }
    else if(key>root->data){

        root->right=removee(root->right,key);
    }
    else{

        if(root->left==NULL && root->right==NULL){
            delete root; 
            return NULL;
        }
        else
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=removee(root->right,temp->data);
        }
    }
    return root;
}
node* min(node* root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL){
        return root;
    }
    else{
        return min(root->left);
    }
}

node* max(node* root){
    if(root==NULL){
        return NULL;
    }
    else if(root->right==NULL){
        return root;
    }
    else{
        return max(root->right);
    }
}


int main(){
    int data;
    cout<<"Enter data for root node ";
    cout<<endl;
    cin>>data;
    node * temp = new node(data);
    cout<<"Enter data for left node "<<endl;
    cin>>data;
    temp->left = new node(data);
    cout<<"Enter data for right node "<<endl;
    cin>>data;
    temp->right = new node(data);
    cout<<"Enter data for left node of left node "<<endl;
    cin>>data;
    temp->left->left = new node(data);
    cout<<"Enter data for right node of left node "<<endl;
    cin>>data;
    temp->left->right = new node(data);
    cout<<"Enter data for left node of right node "<<endl;
    cin>>data;
    temp->right->left = new node(data);
    cout<<"Enter data for right node of right node "<<endl;
    cin>>data;
    temp->right->right = new node(data);
    cout<<"Preorder traversal of tree is "<<endl;
    preorder(temp);
    cout<<endl;
    cout<<"Inorder traversal of tree is "<<endl;
    inorder(temp);
    cout<<endl;
    cout<<"Postorder traversal of tree is "<<endl;
    postorder(temp);
    cout<<endl;
    cout<<"Levelorder traversal of tree is "<<endl;
    levelorder(temp);
    cout<<endl;
    cout<<"Enter data to be insert "<<endl;
    cin>>data;
    insert(temp,data);
    cout<<"Preorder traversal of tree is "<<endl;
    preorder(temp);
    cout<<endl;
    cout<<"Inorder traversal of tree is "<<endl;
    inorder(temp);
    cout<<endl;
    cout<<"Postorder traversal of tree is "<<endl;
    postorder(temp);
    cout<<endl;
    cout<<"Levelorder traversal of tree is "<<endl;
    levelorder(temp);
    cout<<endl;
    cout<<"Enter data to be search "<<endl;
    cin>>data;
    search(temp,data);
    cout<<"Enter data to be remove "<<endl;
    cin>>data;
    removee(temp,data);
    cout<<"Minimum value in tree is "<<min(temp)->data<<endl;
    cout<<"Maximum value in tree is "<<max(temp)->data<<endl;
    cout<<"Updated tree is "<<endl;
    cout<<"Preorder traversal of tree is "<<endl;
    preorder(temp);
    cout<<endl;
    cout<<"Inorder traversal of tree is "<<endl;
    inorder(temp);
    cout<<endl;
    cout<<"Postorder traversal of tree is "<<endl;
    postorder(temp);
    cout<<endl;
    cout<<"Levelorder traversal of tree is "<<endl;
    levelorder(temp);
    cout<<endl;
    return 0;
}
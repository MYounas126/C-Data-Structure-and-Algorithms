#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createBt(node* root) {
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = createBt(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createBt(root->right);

    return root;
}

int main() {
    node* root = NULL;
    root = createBt(root);
    return 0;
}

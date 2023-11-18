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

node* createBt() {
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    
    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = createBt();
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createBt();

    return root;
}

int main() {
    node* root = createBt();
    return 0;
}

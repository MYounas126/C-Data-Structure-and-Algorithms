#include <iostream>
using namespace std;

// Define the structure for a BST node
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    // Constructor to initialize the node
    BSTNode(int val){

        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Helper function to insert a node into the BST
BSTNode* insertNode(BSTNode* root, int value) {
    if (root == NULL) {
        return new BSTNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Helper function to find the minimum value node in a BST
BSTNode* findMin(BSTNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
BSTNode* deleteNode(BSTNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    // Search for the node to be deleted
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        BSTNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// In-order traversal of the BST
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Display the elements of the BST
void display(BSTNode* root) {
    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;
}

int main() {
    // Create a sample BST
    BSTNode* root = nullptr;

    // Insert nodes into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Display the elements of the BST
    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    // Delete a node (e.g., node with value 30)
    root = deleteNode(root, 30);

    // Display the BST after deletion
    cout << "In-order traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up: Free memory
    // (In a real program, you may need to implement a more comprehensive cleanup)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    // Create a new node (named "temp") to be added at the head of the linked list
    node* temp = new node(val);
    
    // Check if head is NULL
    if (head == NULL) {
        head = temp;
    } else {
        // Point the new node's next to the current head
        temp->next = head;
        // Update the head to the new node
        head = temp;
    }
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int val;
    cout << "Enter a value for the node to be added to the linked list: ";
    cin >> val;
    node* head = nullptr;

    // Add the first value to the linked list
    insertAtHead(head, val);

    cout << "Your node is: ";
    print(head);

    cout << "Enter another value to be added to the linked list: ";
    cin >> val;

    // Add another value to the linked list
    insertAtHead(head, val);

    cout << "Your updated linked list is: ";
    print(head);

    return 0;
}

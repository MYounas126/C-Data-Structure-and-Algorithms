#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

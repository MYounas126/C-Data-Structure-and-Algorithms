#include<iostream>
#include<algorithm>
using namespace std;
class Student{
    private:
        int reg_no;
        string name;
        float cgpa;
    public:
        int data;
        Student *left,*right;
        int height;
        Student(){
            reg_no=0;
            name=" ";
            cgpa=0.0;
            left=right=NULL;
            height=1;
        }
        Student(int reg_no,string name,float cgpa){
            this->reg_no=reg_no;
            this->name=name;
            this->cgpa=cgpa;
        }
        int getRegNo(){
            return reg_no;
        }
        string getName(){
            return name;
        }
        float getCgpa(){
            return cgpa;
        }
        void setRegNo(int reg_no){
            this->reg_no=reg_no;
        }
        void setName(string name){
            this->name=name;
        }
        void setCgpa(float cgpa){
            this->cgpa=cgpa;
        }
        void print(){
            cout<<"Reg No: "<<reg_no<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"CGPA: "<<cgpa<<endl;
        }   


int Height(Student* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
Student *leftRotate(Student *x){
    Student *y=x->right;
    Student *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(Height(x->left),Height(x->right))+1;
    y->height=max(Height(y->left),Height(y->right))+1;
    return y;
}
Student *rightRotate(Student *y){
    Student *x=y->left;
    Student *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(Height(y->left),Height(y->right))+1;
    x->height=max(Height(x->left),Height(x->right))+1;
    return x;
}
int getBalanceFactor(Student *node){
    if(node==NULL){
        return 0;
    }
    return Height(node->left)-Height(node->right);
}
Student *insert(Student *root,Student *node){
    if(root==NULL){
        return node;
    }
    if(node->getRegNo()<root->getRegNo()){
        root->left=insert(root->left,node);
    }
    else if(node->getRegNo()>root->getRegNo()){
        root->right=insert(root->right,node);
    }
    else{
        return root;
    }
    root->height=1+max(Height(root->left),Height(root->right));
    int balance=getBalanceFactor(root);
    if(balance>1 && node->getRegNo()<root->left->getRegNo()){
        return rightRotate(root);
    }
    if(balance<-1 && node->getRegNo()>root->right->getRegNo()){
        return leftRotate(root);
    }
    if(balance>1 && node->getRegNo()>root->left->getRegNo()){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && node->getRegNo()<root->right->getRegNo()){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preoder(Student *root){
    if(root!=NULL){
        cout<<root->getRegNo()<<" ";
        preoder(root->left);
        preoder(root->right);
    }
}
};
int main(){

    
    Student s;
    int reg_no;
    string name;
    float cgpa;
    int n;

    cout << "Enter elements in AVL tree: " << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Enter reg no: ";
        cin >> reg_no;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter cgpa: ";
        cin >> cgpa;
        Student* node = new Student(reg_no, name, cgpa);
    }
    cout << "Enter reg no to delete: ";
    cin >> n;
    cout << "Deleted reg no: " << n << endl;
    return 0;
    cout<<"Deleted reg no: "<<n<<endl;
    return 0;


}

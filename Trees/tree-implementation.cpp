#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

};

//it returns root node of the created tree
Node* createdTree(){
    cout<<"enter the value for Node: " <<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    //step 1 create node
    Node* root = new Node(data);
    //step 2 create left subtree
    // cout<<"Enter the left child of "<<root->data<<endl;
    root->left = createdTree();
    //step 3 create right subtree
    // cout<<"Enter the right child of "<<root->data<<endl;
    root->right = createdTree();
    return root; 
};

int main(){
    Node* root = createdTree();
    return 0;
}
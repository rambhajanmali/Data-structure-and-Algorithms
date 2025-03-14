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

//preorder traversal in tree
void preOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    //NLR
    //N
    cout<<root->data<<" ";
    //L
    preOrderTraversal(root->left);
    //R
    preOrderTraversal(root->right);
}

//inorder traversal in tree
void inOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    //LNR
    //L
    inOrderTraversal(root->left);
    //N
    cout<<root->data<<" ";
    //R
    inOrderTraversal(root->right);
}

//postorder traversal in tree
void postOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    //LRN
    //L
    postOrderTraversal(root->left);
    //R
    postOrderTraversal(root->right);
    //N
    cout<<root->data<<" ";
}

int main(){
    Node* root = createdTree();
    // cout << root->data << endl;

    cout<<"printing preorder traversal of the tree"<<endl;
    preOrderTraversal(root);   
    cout<<endl;

    cout<<"printing inorder traversal of the tree"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing postorder traversal of the tree"<<endl;
    postOrderTraversal(root);
    cout<<endl;
    return 0;
}
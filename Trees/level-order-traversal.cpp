#include<iostream>
#include<queue>
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
    root->left = createdTree();
    //step 3 create right subtree
    root->right = createdTree();
    return root; 
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //asli traversal setart karte h

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        
        }
        else{
            //valid node wala case
            cout<<front->data<<" ";

        if(front->left != NULL){
            q.push(front->left);
        }

        if(front->right != NULL){
            q.push(front->right);
        }
        }

        
    }
};

int main(){
    Node* root = createdTree();

    cout<<"level order traversal: ";
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
}
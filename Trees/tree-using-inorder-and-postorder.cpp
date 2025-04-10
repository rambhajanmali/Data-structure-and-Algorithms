#include<iostream>
#include<queue>
#include<map>
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

void createMapping(int inorder[] , int size, map<int,int> &valueToIndexMap) {

    for(int i =0; i < size; i++){

        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

int searchInOrder(int inOrder[], int size, int target){
    for(int i = 0; i < size; i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    return -1; //element not found
}

Node* constructTreeFromPostAndInorderTraversal(map<int,int> &valueToIndexMap, int postOrder[], int inOrder[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int size){
    if(postOrderIndex< 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 case solve krta hu
    int element = postOrder[postOrderIndex];
    postOrderIndex--;
    Node* root = new Node(element);
    //element search karna padega inOrder array me
    int position = valueToIndexMap[element]; //O(1) time complexity
    //baki recurssion shambhal lega
    //right ki call pahle lagegi 
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, position + 1, inOrderEnd, size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, position - 1, size);
    return root;
}

int main(){

    int inOrder[] = {8,14,6,2,10,4};
    int postOrder[] = {8,6,14,4,10,2};
    int size = 6;
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int,int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);
    Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);
    cout<<"printing the entire tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}
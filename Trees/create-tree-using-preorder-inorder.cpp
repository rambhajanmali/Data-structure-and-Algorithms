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
Node* constructTreeFromPreAndInorderTraversal( map<int,int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){

    //Base case
    if(preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 case solve krta hu
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);

    //element search karna padega inOrder array me
    // int position = searchInOrder(inOrder,size ,element);
    int position = valueToIndexMap[element]; //O(1) time complexity
    
    //baki recurssion shambhal lega
    root->left = constructTreeFromPreAndInorderTraversal( valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);
    root->right = constructTreeFromPreAndInorderTraversal( valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

    return root;

}

int main(){
    int inOrder[] = {10,8, 6,2,4,12};
    int preOrder[] = {10,8,6,2,4,12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;

    map<int,int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout<<"printing the entire tree" <<endl;
    levelOrderTraversal(root);
    return 0;
}
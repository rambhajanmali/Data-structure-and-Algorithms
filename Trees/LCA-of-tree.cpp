#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find the Lowest Common Ancestor (LCA)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;

    if (root->value == p->value) return p;
    if (root->value == q->value) return q;

    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL) 
        return NULL;
    else if (leftAns != NULL && rightAns == NULL) 
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL) 
        return rightAns;
    else 
        return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    TreeNode* p = root->left->left;       // Node 4
    TreeNode* q = root->left->right->left; // Node 6

    TreeNode* ans = lowestCommonAncestor(root, p, q);
    
    if (ans != NULL) {
        cout << "Lowest Common Ancestor: " << ans->value << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}

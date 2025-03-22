#include <iostream>
#include <algorithm>
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

// Function to get the height of the tree
int height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    // Get heights of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check the balance condition
    int diff = abs(leftHeight - rightHeight);
    bool currNodeBalanced = (diff <= 1);

    // Recursively check for left and right subtrees
    bool leftBalanced = isBalanced(root->left);
    bool rightBalanced = isBalanced(root->right);

    return currNodeBalanced && leftBalanced && rightBalanced;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    cout << "Is the Tree Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}

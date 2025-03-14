#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

// Function to calculate max depth
int maxDepth(TreeNode* root) {
    // Base case
    if (root == NULL) {
        return 0;
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Max Depth of the Tree: " << maxDepth(root) << endl;

    return 0;
}

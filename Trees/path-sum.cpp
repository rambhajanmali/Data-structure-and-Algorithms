#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve(TreeNode* root, int targetSum, int sum) {
    if (root == NULL) {
        return false;
    }

    sum += root->val;
    if (root->left == NULL && root->right == NULL) {
       //i am currently standing on leaf node
            //verify 
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
    }

     bool leftAns = solve(root->left,targetSum, sum);
     bool rightAns = solve(root->right, targetSum, sum);
        return leftAns ||rightAns;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    bool ans = solve(root, targetSum, sum);
    return ans;
}

int main() {
    // Creating a sample tree:
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \      \
    //  7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists!" << endl;
    } else {
        cout << "No path with sum " << targetSum << " found." << endl;
    }

    return 0;
}

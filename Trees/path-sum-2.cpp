#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find all root-to-leaf paths where the sum equals targetSum
void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Add current node value to sum and path
    sum += root->val;
    temp.push_back(root->val);

    // If at leaf node, check if path sum matches targetSum
    if (root->left == NULL && root->right == NULL) {
        if (sum == targetSum) {
            ans.push_back(temp);
        }
        return;  // Return after checking leaf node
    }

    // Recursively traverse left and right subtrees
    solve(root->left, targetSum, ans, temp, sum);
    solve(root->right, targetSum, ans, temp, sum);
}

// Wrapper function to return all valid paths
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, targetSum, ans, temp, 0);
    return ans;
}

// Function to print the vector of paths
void printPaths(const vector<vector<int>> &paths) {
    for (const auto &path : paths) {
        cout << "[ ";
        for (int num : path) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
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

    vector<vector<int>> ans = pathSum(root, targetSum);

    if (!ans.empty()) {
        cout << "Path(s) with sum " << targetSum << " exist(s):\n";
        printPaths(ans);
    } else {
        cout << "No path with sum " << targetSum << " found." << endl;
    }

    return 0;
}

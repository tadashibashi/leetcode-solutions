/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int checkDepth(TreeNode *node) {
        if (!node) return 0;

        int left = checkDepth(node->left);
        int right = checkDepth(node->right);
        
        if (left == -1 || right == -1 || std::abs(left - right) > 1) return -1;

        return std::max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return checkDepth(root) != -1;
    }
};
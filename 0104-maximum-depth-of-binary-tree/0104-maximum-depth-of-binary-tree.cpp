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
    int delve(TreeNode *node, int level = 1) {
        if (!node->left && !node->right) return level;

        int deepest = level + 1;
        if (node->left) 
            deepest = delve(node->left, level + 1);
        if (node->right)
            deepest = std::max(delve(node->right, level + 1), deepest);
        return deepest;
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return delve(root);
    }
};
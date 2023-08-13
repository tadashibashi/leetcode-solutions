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
    void getMinDepth(TreeNode *node, int depth, int &shortest) {
        if (depth >= shortest) return;
        if (!node->left && !node->right) {
            if (depth < shortest)
                shortest = depth;
            return;
        }

        if (node->left)
            getMinDepth(node->left, depth+1, shortest);
        if (node->right)
            getMinDepth(node->right, depth+1, shortest);
    }

    int minDepth(TreeNode* node) {
        if (!node) return 0;
        
        int shortest = INT_MAX;
        getMinDepth(node, 1, shortest);
        return shortest;
    }
};

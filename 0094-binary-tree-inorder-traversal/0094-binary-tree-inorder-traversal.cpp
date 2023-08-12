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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> answers;
        std::stack<TreeNode *> stack;
        auto cur = root;

        while (!stack.empty() || cur) {
            if (cur) {
                stack.emplace(cur);
                cur = cur->left;
            } else {
                cur = stack.top(); 
                stack.pop();
                answers.push_back(cur->val);
                cur = cur->right;
            }
                
        }

        return answers;
    }
};
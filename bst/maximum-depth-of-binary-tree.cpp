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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0, currDepth = 1;
        dfs(root, maxDepth, currDepth);
        return maxDepth;
    }
    void dfs(TreeNode* node, int &maxDepth, int depth) {
        if(!node) return;
        dfs(node->left, maxDepth, depth + 1);
        dfs(node->right, maxDepth, depth + 1);
        if(!node->left && !node->right) maxDepth = max(maxDepth, depth);
    }
};

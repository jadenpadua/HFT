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
private:
    int postOrder(TreeNode*& node) {
        if(!node) return 0;

        int lDepth = postOrder(node->left);
        int rDepth = postOrder(node->right);

        return max(lDepth, rDepth) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int maxDepth = postOrder(root);
        return maxDepth;
    }
};

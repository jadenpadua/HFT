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
    void postOrder(TreeNode*& node) {
        if(!node) return;

        postOrder(node->left);
        postOrder(node->right);
        swap(node->left, node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        postOrder(root);
        return root;
    }
};

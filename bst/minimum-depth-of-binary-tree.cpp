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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int minDepth = INT_MAX, currDepth = 1;
        inOrderTraversal(root, minDepth, currDepth);
        return minDepth;
    }
    void inOrderTraversal(TreeNode* node, int &minDepth, int currDepth) {
        if(!node) return;
        inOrderTraversal(node->left, minDepth, currDepth + 1);
        if(!node->left && !node->right) minDepth = min(minDepth, currDepth);
        inOrderTraversal(node->right, minDepth, currDepth + 1);
    }
};

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        inOrderTraversal(root, low, high, rangeSum);
        return rangeSum;
    }
    void inOrderTraversal(TreeNode* node, int low, int high, int &rangeSum) {
        if(!node) return;
        inOrderTraversal(node->left, low, high, rangeSum);
        if(node->val >= low && node->val <= high) rangeSum += node->val;
        inOrderTraversal(node->right,low, high, rangeSum);
    }
};

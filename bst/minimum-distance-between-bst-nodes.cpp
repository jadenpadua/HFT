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
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        int minDiff = INT_MAX;
        inOrderTraversal(prev, root, minDiff);
        return minDiff;
    }
    void inOrderTraversal(TreeNode* &prev, TreeNode* node, int &minDiff) {
        if(!node) return;

        inOrderTraversal(prev, node->left, minDiff);
        if(prev) minDiff = min(minDiff, abs(prev->val - node->val));
        prev = node;
        inOrderTraversal(prev, node->right, minDiff);

    }
    
};

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
    int postOrder(TreeNode*& node, int& maxDiameter) {
        if(!node) return 0;

        int left = postOrder(node->left, maxDiameter);
        int right = postOrder(node->right, maxDiameter);
        maxDiameter = max(maxDiameter, left + right);

        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter {};
        postOrder(root, maxDiameter);
        return maxDiameter;
    }
};

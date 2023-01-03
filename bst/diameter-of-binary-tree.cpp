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

    int dfs(TreeNode* node, int &diameter) {
        if(!node) return 0;

        int leftDist = dfs(node->left, diameter);
        int rightDist = dfs(node->right, diameter);
        diameter = max(diameter, leftDist + rightDist);

        return max(leftDist, rightDist) + 1;

    } 
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter {};
        dfs(root, diameter);
        return diameter; 
        
    }
};

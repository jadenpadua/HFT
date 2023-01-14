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
    int postOrder(TreeNode* node, int depth) {
        if(!node) return 0;
    
        int lDepth = postOrder(node->left, depth + 1);
        int rDepth = postOrder(node->right, depth + 1);

        if(abs(rDepth - lDepth) > 1 || lDepth == -1 || rDepth == -1) return -1;
        
        return max(lDepth, rDepth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth {};
        return postOrder(root, depth) != -1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* dfs(TreeNode*& node, TreeNode* p, TreeNode* q) {
        if(node->val > p->val && node->val > q->val) {
            return dfs(node->left, p, q);
        }
        else if(node->val < p->val && node->val < q->val) {
            return dfs(node->right, p, q);
        }
        return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        
        return dfs(root, p, q);
    }
};

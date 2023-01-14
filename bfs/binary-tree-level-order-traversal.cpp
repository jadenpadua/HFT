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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res {};
        queue<TreeNode*> q {};
        q.push(root);

        while(!q.empty()) {
            vector<int> row {};
            int n = q.size(); 
            for(int i = 0; i < n; ++i) {
                TreeNode* popped = q.front(); q.pop();
                if(popped->left) q.push(popped->left);
                if(popped->right) q.push(popped->right);
                
                row.push_back(popped->val);
            }
            res.push_back(row);
        }
        return res;
    }
};

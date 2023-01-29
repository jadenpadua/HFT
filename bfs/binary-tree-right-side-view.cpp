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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> res {};
        queue<TreeNode*> q {};
        q.push(root);

        while(!q.empty()) {
            int n = q.size(), last = -1;
            for(int i = 0; i < n; ++i) {
                TreeNode* popped = q.front(); q.pop();
                last = popped->val;

                if(popped->left != NULL) q.push(popped->left);
                if(popped->right != NULL) q.push(popped->right); 
            }
            res.push_back(last);
        }
        return res;
    }
};

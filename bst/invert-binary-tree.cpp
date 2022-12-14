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
 /*
 * @description: Solution 1 is postorder recursive traversal starting at leaves, then just call swap on every node
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};
/*
* @description: Solution 2 is iterative using BFS and a queue, start at root and swap each for each level
*/
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()) {
            TreeNode *currNode = q.front(); q.pop();
            swap(currNode->left, currNode->right);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        return root;
    }
};

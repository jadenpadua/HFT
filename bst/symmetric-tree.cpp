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
    bool isSubtreeSymmetric(TreeNode* n1, TreeNode* n2) {
        if(n1 == nullptr && n2 == nullptr) return true;
        else if(n1 == nullptr || n2 == nullptr) return false;
        else if(n1->val != n2->val) return false;

        return isSubtreeSymmetric(n1->left, n2->right) && isSubtreeSymmetric(n1->right, n2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSubtreeSymmetric(root->left, root->right);
    }
};

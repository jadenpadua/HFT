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
    TreeNode* createTree(vector<int> nums, int left, int right) {
        if(left > right) return nullptr;

        int mid = left + (right - left) / 2;
        
        TreeNode *node = new TreeNode(nums[mid]);

        node->left = createTree(nums, left, mid-1);
        node->right = createTree(nums, mid+1, right);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        TreeNode* bst = createTree(nums, left, right);
        return bst;
    }
};

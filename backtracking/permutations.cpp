class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>>& res, int i, int n) {
        if(i == n) {
            res.push_back(nums);
            return;
        }
        for(int j = i; j <= n; ++j) {
            swap(nums[i], nums[j]);
            backtrack(nums,res, i+1, n);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res {};
        backtrack(nums, res, 0, nums.size() - 1);
        return res;
    }
};

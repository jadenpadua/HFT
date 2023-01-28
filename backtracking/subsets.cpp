class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& currList, vector<int> nums, int ptr) {
        res.push_back(currList);
        for(int i = ptr; i < nums.size(); ++i) {
            currList.push_back(nums[i]);
            backtrack(res, currList, nums, i+1);
            currList.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {};
        vector<int> currList {};
        backtrack(res, currList, nums, 0);
        return res;
    }
};

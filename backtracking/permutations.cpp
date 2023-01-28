class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& currList, vector<int> nums) {
        if(currList.size() == nums.size()) {
            res.push_back(currList);
        }
        else {
            for(int i = 0; i < nums.size(); ++i) {
                if(find(currList.begin(), currList.end(), nums[i]) != currList.end()) continue;
                currList.push_back(nums[i]);
                backtrack(res, currList, nums);
                currList.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res {};
        vector<int> currList {};
        backtrack(res, currList, nums);
        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();
        pair<int,int> dp = {nums[0], max(nums[0], nums[1])};

        for(int i = 2; i < n; ++i) {
            int temp = dp.second;
            dp.second = max(dp.second, dp.first + nums[i]);
            dp.first = temp;
        }
        return dp.second;
    }
};

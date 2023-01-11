class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int runningSum {};
        for(int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            nums[i] = runningSum;
        }
        return nums;
    }
};

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int maxSum = 0, currSum = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            currSum = nums[i];
            while(i < nums.size() - 1 && nums[i] < nums[i + 1]) {
                currSum += nums[i + 1];
                i += 1;
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

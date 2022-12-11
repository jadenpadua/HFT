/**
* @description:
* Step 1: iterate through arr
* Step 2: Build prefix sum of current SubArr
* Step 3: If prefix sum < 0 its useless, disregard it & reset to 0
* Step 4: Max sub arr is currentMax and the prefixSum + the current number we are on
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prefixSum < 0) {
                prefixSum = 0;
            }
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum);
        }
        return maxSum;
    }
};

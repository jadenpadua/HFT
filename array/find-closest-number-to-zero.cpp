class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int c = INT_MAX;
        bool showLargest = false;
        for(int i = 0; i < nums.size(); ++i) {
            if(abs(nums[i]) == abs(c)) c = max(c, nums[i]);
            else if(abs(nums[i]) < abs(c)) c = nums[i];
        }
        return c;
     }
};

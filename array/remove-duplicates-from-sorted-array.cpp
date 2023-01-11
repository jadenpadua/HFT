class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), count {};
        for(int i = 1; i < n; ++i) {
            if(nums[i-1] == nums[i]) ++count;
            else nums[i - count] = nums[i];
        }
        return n - count;
    }
};

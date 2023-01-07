class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIdx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                nums[lastNonZeroIdx] = nums[i];
                ++lastNonZeroIdx;
            }
        }
        for(int i = lastNonZeroIdx; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

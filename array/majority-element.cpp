class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority = nums[0], count = 1; 
        for(int i = 1; i < n; ++i) {
            if(count == 0) {
                ++count;
                majority = nums[i];
            }
            else if(nums[i] == majority) ++count;
            else --count;
        }
        return majority;
    }
};

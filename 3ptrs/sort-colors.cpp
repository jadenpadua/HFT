class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) return;
        
        int left = 0, right = nums.size() - 1;
        int i = 0;
        
        while(i <= right && left < right) {
            if(nums[i] == 0) {
                swap(nums[i++], nums[left++]);
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[right--]);
            }
            else {
                ++i;
            }
        }

    }
};

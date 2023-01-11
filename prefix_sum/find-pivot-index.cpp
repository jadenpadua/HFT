class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls {}, rs {};
        for(int num: nums) rs += num;
        for(int i = 0; i < nums.size(); ++i) {
            ls += nums[i];
            if(ls == rs) return i;
            rs -= nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res {};
        for(int num: nums) res ^= num;
        return res;
    }
};

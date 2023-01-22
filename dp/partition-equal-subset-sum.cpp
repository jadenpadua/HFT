class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums) sum += i;
        if(sum % 2 == 1) return false;

        set<int> dp {}; dp.insert(0);
        int half = sum / 2;

        for(int i = 0; i < nums.size(); ++i) {
            set<int> nextDP {};
            for(int item: dp) {
                if(item + nums[i] == half) return true;
                nextDP.insert(item);
                nextDP.insert(item + nums[i]);
            }
            dp = nextDP;
        }
        return false;
    }
};

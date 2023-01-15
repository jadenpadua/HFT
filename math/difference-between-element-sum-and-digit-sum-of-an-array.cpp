class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int runningSum {};
        int digitSum {};
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            runningSum += num;
            
            while(num > 0) {
                int d = num % 10;
                digitSum += d;
                num /= 10;
            }
        }
        return abs(runningSum - digitSum);
    }
};

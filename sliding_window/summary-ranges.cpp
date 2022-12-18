class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> minRanges;
        for(int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            while(i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
                i += 1;
            
            if(start != nums[i]) {
                minRanges.push_back(to_string(start)+"->"+to_string(nums[i]));
            }
            else {
                minRanges.push_back(to_string(start));
            }
        }
        return minRanges;
    }
};

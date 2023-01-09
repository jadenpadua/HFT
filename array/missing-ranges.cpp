class Solution {
private:
    string getRange(int start, int end) {
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long int low = (long)lower - 1;

        if(nums.size() <= 0) {
            res.push_back(getRange(lower, upper));
            return res;
        }

        for(int i = 0; i <= nums.size(); i++) {
            long int curr = (i == nums.size() ? (long)upper + 1 : (long)nums[i]);
            if(curr - low > 1) {
                res.push_back(getRange(low + 1, curr - 1));
            }
            low = curr;
        }
        return res;
    }
};

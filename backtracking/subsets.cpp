class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs {{}};
        for(int i = 0; i < nums.size(); ++i) {
            int n = subs.size();
            for(int j = 0; j < n; ++j) {
                vector<int> newMember = subs[j];
                newMember.push_back(nums[i]);
                subs.push_back(newMember);
            }
        }
        return subs;
    }
};

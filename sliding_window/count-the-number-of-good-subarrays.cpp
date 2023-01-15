class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        
        long long ans = 0;
        long long pairs = 0;
        map<int,int> freq;
        for(int right = 0; right < n; ++right) {
            pairs += freq[nums[right]];
            ++freq[nums[right]];
            
            while(pairs >= k) {
                freq[nums[left]] -= 1;
                pairs -= freq[nums[left]];
                ++left;
            }
            ans += left;
        }
        return ans;
    }
};

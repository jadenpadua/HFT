class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap = {{0,1}};
        int res {}, runningSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int prefixSum = runningSum - k;
            if(umap.find(prefixSum) != umap.end()) res += umap[prefixSum];
            umap[runningSum]++;
        }
        return res;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> umap {
            {0,1},
        };
        int runningSum {};
        int res {};
        for(int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int prefSumToFind = runningSum - k;
            if(umap.find(prefSumToFind) != umap.end()) {
                res += umap[prefSumToFind];
            }
            umap[runningSum]++;
        }
        return res;
    }
};

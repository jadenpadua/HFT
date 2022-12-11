class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int targetSum = target - nums[i];
            if (umap.find(targetSum) != umap.end())
                return {umap[targetSum], i};
            umap[nums[i]] = i;
        }
        return {-1, -1};
    }
};

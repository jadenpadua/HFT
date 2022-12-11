/*
* @description: create umap where key is target sum to find & value is the index where that target sum is located
*/
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

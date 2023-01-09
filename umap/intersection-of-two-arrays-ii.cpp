class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res {};

        unordered_map<int,int> umap {};
        for(int num: nums1) ++umap[num];

        for(int i = 0; i < nums2.size(); ++i) {
            if(umap[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                umap[nums2[i]]--;
            }
        }
        return res;
    }
};

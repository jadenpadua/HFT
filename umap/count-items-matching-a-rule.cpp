class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string,int> umap = {
            {"type", 0},
            {"color", 1},
            {"name", 2},
        };

        int res = 0;
        for(auto& item: items) {
            if(item[umap[ruleKey]] == ruleValue) res++;
        }
        return res;
    }
};

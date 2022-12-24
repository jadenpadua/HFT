class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map <char,int> umap;
        for(char c: s) umap[c]++;

        int curr = umap[s[0]];
        for(auto it: umap) {
            if(it.second != curr) return false;
            curr = it.second;
        }
        return true;
    }
};

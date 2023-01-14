class Solution {
public:
    int longestPalindrome(string s) {
        int res {};
        unordered_map<char,int> umap;
        for(char c: s) ++umap[c];

        for(auto it: umap) {
            res += (it.second / 2) * 2;
            if(res % 2 == 0 && it.second % 2 == 1) ++res;
        }
        return res;
    }
};

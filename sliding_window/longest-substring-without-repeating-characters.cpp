class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len {}, maxLen {};
        int l {};
        unordered_map<char, int> umap;

        for(int r = 0; r < s.size(); ++r) {
            ++umap[s[r]]; ++len;
            while(umap[s[r]] > 1) {
                --umap[s[l++]]; --len;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

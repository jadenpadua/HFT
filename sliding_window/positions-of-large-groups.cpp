class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int left {}, right {}, n = s.length();
        // 2 ptrs, when left != right we push back to res if window >= 3
        for(right = 0; right < n; ++right) {
            if(s[left] != s[right]) {
                if(right - left >= 3) res.push_back({left, right-1});
                left = right;
            }
        }
        // case where we never break consecutive string
        if(right - left >= 3) res.push_back({left, right-1});
        return res;
    }
};

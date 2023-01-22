class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for(int i = 0; i <= s.size(); ++i) {
            for(auto w: wordDict) {
                if(dp[i]) {
                    string currSubstr = s.substr(i, w.size());
                    if(currSubstr == w) dp[i + w.size()] = true;
                }
            }
        }
        return dp[n];
    }
};

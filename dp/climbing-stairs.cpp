class Solution {
private:
    int recurse(int n, unordered_map<int,int> &dp) {
        if(dp.find(n) != dp.end()) return dp[n];
        dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
        return dp[n];

    }
public:
    int climbStairs(int n) {
        unordered_map<int,int> dp = {
            {0,1},
            {1,1}
        };
        int numWays = recurse(n, dp);
        return numWays;
    }
};

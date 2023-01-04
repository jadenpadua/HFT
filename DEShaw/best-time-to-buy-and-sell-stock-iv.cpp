#include <iostream>
#include <algorithm>

int calcMaxProfit(int prices[], int n, int k) {
    int dp[k+1][n];
    
    for(int i=0; i <=k; ++i) {
        int max_diff = -prices[0];
        for(int j= 1; j < n; ++j) {
            dp[i][j] = std::max(dp[i][j-1], prices[j] + max_diff);
            max_diff = std::max(max_diff, dp[i-1][j] - prices[j]);
        }
    }
    return dp[k][n-1];
}

int main() {
    int prices[] = {7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(prices[0]), k = 2;
    std::cout << "Max profit: " << calcMaxProfit(prices, n, k) << std::endl;
    return 0;
}

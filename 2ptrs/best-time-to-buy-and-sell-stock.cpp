/**
* @description: 2 ptrs, right ptr keeps moving along the prices, left ptr updates to right ptr if right ptr price is lower
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxProfit = 0;

        while(right < prices.size()) {
            if (prices[left] < prices[right]) {
                int currProfit = prices[right] - prices[left];
                maxProfit = max(maxProfit, currProfit);
            }
            else {
                left = right;
            }
            right += 1;
        }
        return maxProfit;
    }
};

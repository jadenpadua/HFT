/**
* @description:
* Step 1: We need to keep tabs on the currMax and currMin prod in the current kadanes subarray you are on
* Step 2: three possibilities will arise to update your currMaxSubArray:
            1. currMaxProd * current number you are on
            2. currMinProd * current number you are on
            3. the number itself
* Step 3: Calculate the min & max of these three possibilites in your curr subarray to use later (DP)
* Step 4: your total is just the max of your currTotal + any new currMaxSubArray Prod
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int totalMaxProd = *max_element(nums.begin(), nums.end());
        int currMaxProd = 1, currMinProd = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int p1 = currMaxProd * nums[i], p2 = currMinProd * nums[i];
            int p3 = nums[i];

            currMaxProd = max(p3, max(p1, p2));
            currMinProd = min(p3, min(p1, p2));
            totalMaxProd = max(totalMaxProd, currMaxProd);
        }
        return totalMaxProd;
    }
};

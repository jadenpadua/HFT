/**
* Step 1: Iterate forward by compounding products of all numbers to the LEFT of curr num
* Step 2: Iterate backwards by compounding products of all number to the RIGHT of curr num
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);        
        int compProd = 1;

        for(int i = 0; i < nums.size(); i++) {
            res[i] *= compProd;
            compProd *= nums[i];
        }
        
        compProd = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= compProd;
            compProd *= nums[i];
        }

        return res;
    }
};

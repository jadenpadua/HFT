/**
* @description:
* Step 1: Sort the array
* Step 2: iterate through array with 3 pointers, one at current i, another at i + 1, last at end of the array
* Step 3: since arr is sorted, if i > 0 and nums[i] == nums[i-1] the curr i was already calculated in i-1 case, so skip this
* Step 4: For each iteraion i, we loop until p2 == p3 which means all combinations in that iteration have been exhausted
* Step 5: Calculate sum of 3 pointers, if sum < 0 then move p2 up, if sum >0 then move p3 down, can do this bc arr is sorted
* Step 6: if ptrSum == 0, add to res, arbitrarily update p2 up one until we reach a non duplicate value (to avoid duplicates)
* Step 7: we do not need to update p3 down one because our next while loop iteration will take care of it, if sum is > 0
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        if(nums[0] > 0) return {};

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int p1 = i, p2 = i + 1, p3 = nums.size() - 1;
            while(p2 < p3) {
                int ptrSum = nums[p1] + nums[p2] + nums[p3];
                if(ptrSum > 0) {
                    p3 -= 1;
                }
                else if(ptrSum < 0) {
                    p2 += 1;
                }
                else {
                    res.push_back({nums[p1], nums[p2], nums[p3]});
                    p2 += 1;
                    while(nums[p2] == nums[p2 - 1] && p2 < p3) p2 += 1;
                }
            }
        }
        return res;
    }
};

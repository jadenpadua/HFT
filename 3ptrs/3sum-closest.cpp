class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDist = INT_MAX;
        int closestTriplet = INT_MAX;

        for(int i = 0; i < nums.size(); ++i) {
            int p1 = i, p2 = i + 1, p3 = nums.size() - 1;
            while(p2 < p3) {
                int currTriplet = nums[p1] + nums[p2] + nums[p3];
                int currDist = abs(currTriplet - target);
                if(currDist < minDist) {
                    minDist = currDist;
                    closestTriplet = currTriplet;
                }
                if(currTriplet > target) {
                    p3 -= 1;
                }
                else {
                    p2 += 1;
                }
            }
        }
        return closestTriplet;
    }
};

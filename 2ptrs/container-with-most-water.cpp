/**
* @description:
* Step 1: 2 ptr approach calculate area by truncating the height of both points (take min of both pointer values)
* Step 2: greedily move the pointer that has the lowest value
* Step 3: Keep tabs on absolute max and break when the pointers collide
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        while(left < right) {
            int dist = right - left;
            int currArea = min(height[left], height[right]) * dist;
            maxArea = max(maxArea, currArea);

            if(height[left] < height[right]) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }
        return maxArea;
    }
};
